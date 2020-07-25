
#include <bits/stdc++.h> 

using namespace std; 
struct Node { 
	int data; 
	struct Node* prev, *next; 
}; 
struct Node* getNode(int data) 
{ 
	
	struct Node* newNode = 
		(struct Node*)malloc(sizeof(struct Node)); 


	newNode->data = data; 
	newNode->prev = newNode->next = NULL; 
	return newNode; 
} 
void sortedInsert(struct Node** head_ref, struct Node* newNode) 
{ 
	struct Node* current; 


	if (*head_ref == NULL) 
		*head_ref = newNode; 

	else if ((*head_ref)->data >= newNode->data) { 
		newNode->next = *head_ref; 
		newNode->next->prev = newNode; 
		*head_ref = newNode; 
	} 

	else { 
		current = *head_ref; 


		while (current->next != NULL && 
			current->next->data < newNode->data) 
			current = current->next; 

		newNode->next = current->next; 


		if (current->next != NULL) 
			newNode->next->prev = newNode; 

		current->next = newNode; 
		newNode->prev = current; 
	} 
} 

void printList(struct Node* head) 
{ 
	while (head != NULL) { 
		cout << head->data << " "; 
		head = head->next; 
	} 
} 


int main() 
{ 
	
	struct Node* head = NULL; 


	struct Node* new_node = getNode(8); 
	sortedInsert(&head, new_node); 
	new_node = getNode(5); 
	sortedInsert(&head, new_node); 
	new_node = getNode(3); 
	sortedInsert(&head, new_node); 
	new_node = getNode(10); 
	sortedInsert(&head, new_node); 
	new_node = getNode(12); 
	sortedInsert(&head, new_node); 
	new_node = getNode(9); 
	sortedInsert(&head, new_node); 

	cout << "Created Doubly Linked Listn"; 
	printList(head); 
	return 0; 
} 
