// A complete working C++ program to 
// demonstrate all insertion methods 
#include <bits/stdc++.h> 
using namespace std; 

// A linked list node 
class Node 
{ 
	public: 
	int data; 
	Node* next; 
	Node* prev; 
}; 

//Can also be implemented using struct and then initialized using a constructor.
struct Node{
	int data;
	Node *next,*prev;
	Node(int x){
		data= x;
		next = prev = NULL;
	}
}

void push(Node** head_ref, int new_data) 
{ 

	Node* new_node = new Node(); 


	new_node->data = new_data; 


	new_node->next = (*head_ref); 
	new_node->prev = NULL; 


	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 


	(*head_ref) = new_node; 
} 

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(Node* prev_node, int new_data) 
{ 

	if (prev_node == NULL) 
	{ 
		cout<<"the given previous node cannot be NULL"; 
		return; 
	} 


	Node* new_node = new Node(); 


	new_node->data = new_data; 

		new_node->next = prev_node->next; 

	prev_node->next = new_node; 


	new_node->prev = prev_node; 


	if (new_node->next != NULL) 
		new_node->next->prev = new_node; 
} 

/* Given a reference (pointer to pointer) to the head 
of a DLL and an int, appends a new node at the end */
void append(Node** head_ref, int new_data) 
{ 

	Node* new_node = new Node(); 

	Node* last = *head_ref; /* used in step 5*/

	new_node->data = new_data; 

	new_node->next = NULL; 


	if (*head_ref == NULL) 
	{ 
		new_node->prev = NULL; 
		*head_ref = new_node; 
		return; 
	} 


	while (last->next != NULL) 
		last = last->next; 

	last->next = new_node; 


	new_node->prev = last; 

	return; 
} 


// linked list starting from the given node 
void printList(Node* node) 
{ 
	Node* last; 
	cout<<"\nTraversal in forward direction \n"; 
	while (node != NULL) 
	{ 
		cout<<" "<<node->data<<" "; 
		last = node; 
		node = node->next; 
	} 

	cout<<"\nTraversal in reverse direction \n"; 
	while (last != NULL) 
	{ 
		cout<<" "<<last->data<<" "; 
		last = last->prev; 
	} 
} 


int main() 
{ 
	/* Start with the empty list */
	Node* head = NULL; 

	// Insert 6. So linked list becomes 6->NULL 
	append(&head, 6); 

	// Insert 7 at the beginning. So 
	// linked list becomes 7->6->NULL 
	push(&head, 7); 

	// Insert 1 at the beginning. So 
	// linked list becomes 1->7->6->NULL 
	push(&head, 1); 

	// Insert 4 at the end. So linked 
	// list becomes 1->7->6->4->NULL 
	append(&head, 4); 

	// Insert 8, after 7. So linked 
	// list becomes 1->7->8->6->4->NULL 
	insertAfter(head->next, 8); 

	cout << "Created DLL is: "; 
	printList(head); 

	return 0; 
} 

// This is code is contributed by rathbhupendra 
