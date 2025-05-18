// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class node_BST 
{
public:
    node_BST(string name, int id);
    int get_ID();
    string get_name();
    node_BST* p = NULL;
    node_BST* L = NULL;
    node_BST* R = NULL;
private:
    string Name;
    int ID;
};

node_BST::node_BST(string name, int id) 
{
    Name = name;
    ID = id;
}

string node_BST::get_name() 
{
    return Name;
}
int node_BST::get_ID()
{
    return ID;
}

class BST {
public:
    void InsertRequest_BST(string name, int id);
    node_BST* SearchRequest_BST(int id);
    void printBST();
    void Transplant(node_BST* u, node_BST* v);
    void DeleteRequest_BST(int id);
    string empty_BST();
private:
    node_BST* parent = NULL;
};
string BST::empty_BST()
{
    string save;
    if (parent == NULL)
    {
        save = "*Empity*";
        return save;
    }
    else
    {
        save = "not_Empity";
        return save;
    }
}

node_BST* BST::SearchRequest_BST(int id)
{
    node_BST* x = parent;
    while (x != NULL)
    {
        if (id == x->get_ID())
        {
            return x;
        }
        else if (id < x->get_ID())
        {
            x = x->L;
        }
        else if (id > x->get_ID())
        {
            x = x->R;
        }
        else
        {
            cout << "** this id not found **";
            return nullptr;
        }
    }
}
void BST::InsertRequest_BST(string name, int id)
{
    node_BST* newNode = new node_BST(name, id);
    node_BST* y = NULL;
    node_BST* x = parent;
    node_BST* z = SearchRequest_BST(id);
    if (z!=0)
    {
        cout << "this id is already exist" << endl;
        return;
    }
    while (x != NULL) 
    {
        y = x;
        if (id < x->get_ID()) 
        {
            x = x->L;
        }
        else
        {
            x = x->R;
        }
    }
    if (y == NULL)
    {
        parent = newNode;
    }
    else if (id < y->get_ID()) 
    {
        y->L = newNode;
        newNode->p = y;
    }
    else {
        y->R = newNode;
        newNode->p = y;
    }
}

node_BST* Tree_minimum(node_BST* node)
{
    while (node->L!=NULL)
    {
        node=node->L;
    }
    return node;
}
void BST::Transplant(node_BST* u, node_BST* v) 
{
    if (u == parent) 
    {
        parent = v;
    }
    else if (u->p->L == u) 
    {
        u->p->L = v;
    }
    else 
    {
        u->p->R = v;
    }
    if (v != nullptr) 
    {
        v->p = u->p;
    }
}
void BST::DeleteRequest_BST(int id) 
{
    node_BST* x = SearchRequest_BST(id);
    if (x == NULL)
    {
        return;
    }
    if (x->R == NULL) 
    {
        Transplant(x, x->L);
    }
    else if (x->L == NULL)
    {
        Transplant(x, x->R);
    }
    else 
    {
        node_BST* y = Tree_minimum(x->R);
        if (y->p != x) 
        {
            Transplant(y, y->R);
            y->R = x->R;
            y->R->p = y;
        }
        Transplant(x, y);
        y->L = x->L;
        y->L->p = y;
    }
}

void preorder_Traversal(node_BST* node) 
{
    if (node != NULL) 
    {
        cout << "ID: " << node->get_ID() << ", Name: " << node->get_name() << endl;
        preorder_Traversal(node->L);
        preorder_Traversal(node->R);
    }
}

void BST::printBST() 
{
    preorder_Traversal(parent);
}
class node_heap
{
public:
    node_heap();
    node_heap(int id, int priority);
    int get_ID();
    int get_priority();
    void set_ID(int id);
    void set_priority(int priority);
private:
    int Priority;
    int ID;
};
node_heap::node_heap()
{

}

node_heap::node_heap(int id, int priority)
{
    ID = id;
    Priority = priority;
}
void node_heap::set_ID(int id)
{
    ID = id;
}
void node_heap::set_priority(int priority)
{
    Priority = priority;
}
int node_heap::get_priority()
{
    return Priority;
}
int node_heap::get_ID()
{
    return ID;
}
int D_id=0;
class max_heap 
{
public:
    max_heap();
    node_heap heap[100];
    int parent(int x);
    int left(int x);
    int right(int x);
    bool isEmptyHeap();
    void maxheapify(int index);
    void increasePriority(int id, int newPriority);
    void insertHeap(int id,int priority);
    void print_Levelorder();
    void processHighestPriorityRequest();
    void deleteMaxHeap();
    void Delete(int id);

private:
    int heap_size = 0;
};
max_heap::max_heap() {

}
int max_heap::parent(int x)
{
    return (x - 1) / 2;
}
int max_heap::left(int x)
{
    return 2 * x + 1;
}
int max_heap::right(int x)
{
    return 2 * x + 2;
}
bool max_heap::isEmptyHeap()
{
    return heap_size == 0;
}
void max_heap::maxheapify(int index)
{
    int L = left(index);
    int R = right(index);
    int largest = index;
    if (L<heap_size && heap[L].get_priority()>heap[index].get_priority())
    {
        largest = L;
    }
    else if (R<heap_size && heap[R].get_priority()>heap[index].get_priority())
    {
        largest = R;
    }
    if (largest != index)
    {
        swap(heap[index],heap[largest]);
        maxheapify(largest);
    }
}
void max_heap::increasePriority(int id, int newPriority)
{
    int i = 0;
    while (i<heap_size && heap[i].get_ID()!=id)
    {
        i++;
    }
    if (newPriority<heap[i].get_priority())
    {
        cout << "** new priority is smaller than current one **";
        return;
    }
    heap[i].set_priority(newPriority) ;
    while (i>0 && heap[parent(i)].get_priority()< heap[i].get_priority())
    {
        swap(heap[i], heap[parent(i)]);
            i = parent(i);
    }

}
void max_heap::insertHeap(int id, int priority)
{
    heap_size= heap_size+1;
    heap[heap_size - 1].set_ID(id);
    heap[heap_size - 1].set_priority(INT_MIN);
    increasePriority(id, priority);
}
void max_heap::print_Levelorder()
{
    int i = 0;
    while (i<heap_size)
    {
        cout << "ID:" << heap[i].get_ID() << ",priority:" << heap[i].get_priority()<<endl;
        i++;

    }
    cout << endl;
}
void max_heap::deleteMaxHeap()
{
    
    if (heap_size!=0) 
    {
        node_heap maximum = heap[0];
        D_id = maximum.get_ID();
        heap[0] = heap[heap_size - 1];
        heap_size= heap_size-1;
        maxheapify(0);
    }

}
void max_heap::Delete(int id)
{
    int i = 0;
    while (i < heap_size) 
    {
        if (heap[i].get_ID() == id) 
        {
            break; 
        }
        i++;
    }
    if (i == heap_size) {
        std::cout << " ** this id not found **" << std::endl;
        return;
    }
    heap[i] = heap[heap_size - 1];
    heap_size= heap_size-1;
    maxheapify(i);

}
void max_heap::processHighestPriorityRequest()
{    

}



int main() {
    BST tree;
    max_heap heap;
    string x;
    string Name;
    int ID = 0;
    int Priority = 0;
    cout << "list: 1.insert / 2.search in BST / 3.Delete / 4.search and delete in BST&heap  / 5.extract max in heap&BST / 6.increase Priority in heap / ";
    cout << "7.print_BST / 8.print_heap" << endl;
    cout << endl;
    while (true)
    {
        int choose_item;
        cout << "which item do you want to run?(write Num from menue)  *";
        cin >> choose_item;
        if (choose_item == 1)
        {
            cout << "Name: ";
            cin >> Name;
            cout << "ID: ";
            cin >> ID;
            cout << "Priority: ";
            cin >> Priority;
            tree.InsertRequest_BST(Name, ID);
            heap.insertHeap(ID, Priority);
        }
        else if (choose_item == 2)
        {
            int search;
            cout << "ID you want to search: ";
            cin >> search;
            node_BST* id = tree.SearchRequest_BST(search);
            cout << "  ->  ID = " << id->get_ID() << ", Name = " << id->get_name() << endl;
        }
        else if (choose_item == 3)
        {
            int delete_item;
            cout << "ID you want to Delete: ";
            cin >> delete_item;
            tree.DeleteRequest_BST(delete_item);
            heap.Delete(delete_item);
        }
        else if (choose_item == 4)
        {
            int delete_search_item;
            cout << "ID you want to search and Delete: ";
            cin >> delete_search_item;
            tree.SearchRequest_BST(delete_search_item);
            tree.DeleteRequest_BST(delete_search_item);
            heap.Delete(delete_search_item);
        }
        else if (choose_item == 5)
        {
            heap.deleteMaxHeap();
            tree.DeleteRequest_BST(D_id);
        }
        else if (choose_item == 6)
        {
            int id;
            int new_Priority;
            cout << "ID you want to increase Priority for: ";
            cin >> id;
            cout << "new Priority: ";
            cin >> new_Priority;
            heap.increasePriority(id, new_Priority);
        }
        else if (choose_item == 7)
        {
            cout << "print BST:" << endl;
            tree.printBST();
        }
        else if (choose_item == 8)
        {
            cout << "print max_heap:" << endl;
            heap.print_Levelorder();
        }

    }

    return 0;
}
