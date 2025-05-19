# Request_Algoritm
🚀 Request Management System using BST and MaxHeap

A C++ project for managing requests with functionalities such as insertion, search, deletion, priority update, and removal of the highest-priority request, all using Binary Search Tree (BST) and MaxHeap data structures.

📌 Project Description

This system allows you to manage user requests efficiently.
Each request contains:

Name (string)
ID (int)
Priority (int)


To organize and access the data quickly, two data structures are implemented:

Binary Search Tree (BST) → Sorted by ID
MaxHeap → Sorted by Priority


✨ Features

✅ Add a new request using Name, ID, and Priority

🔍 Search for a request by ID using BST

❌ Delete a request by ID

🔼 Increase the priority of a request

⚡️ Delete the request with the highest priority

🖨 Print BST using Preorder traversal

🖨 Print MaxHeap using Level Order traversal



🧠 Data Structures

📘 Binary Search Tree (BST)

Each BST node contains:
Name
ID
Left, Right, and Parent pointers

BST is sorted based on the ID of requests.

🔺 MaxHeap

Each MaxHeap node contains:
ID
Priority

MaxHeap maintains the node with the highest priority at the top.



🧱 Class Structure

The system is built using 4 main classes:

BSTNode: Node structure for BST
BST: Tree structure and operations
MaxHeapNode: Node structure for MaxHeap
MaxHeap: Heap structure and operations
Plus, a main.cpp file that demonstrates how the system works with sample inputs.

💻 Technologies Used

Language: C++
Data Structures: Binary Search Tree (BST) and MaxHeap

📂 Repository

GitHub: Request_Algoritm
