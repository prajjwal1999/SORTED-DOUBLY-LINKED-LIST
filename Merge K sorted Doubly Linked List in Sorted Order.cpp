
#include <bits/stdc++.h> 
using namespace std; 


struct Node { 
	int data; 
	Node* next; 
	Node* prev; 
}; 

void append(struct Node** head_ref, int new_data) 
{ 
	 
	struct Node* new_node 
		= (struct Node*)malloc(sizeof(struct Node)); 

	struct Node* last = *head_ref; 

	
	new_node->data = new_data; 

L 
	new_node->next = NULL; 

	if (*head_ref == NULL) { 
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

 
void printList(Node* node) 
{ 
	Node* last; 


	while (node != NULL) { 
		cout << node->data << " "; 
		last = node; 
		node = node->next; 
	} 
} 


Node* mergeList(Node* p, Node* q) 
{ 
	Node* s = NULL; 

	// If any of the list is empty 
	if (p == NULL || q == NULL) { 
		return (p == NULL ? q : p); 
	} 

	// Comparison the data of two linked list 
	if (p->data < q->data) { 
		p->prev = s; 
		s = p; 
		p = p->next; 
	} 
	else { 
		q->prev = s; 
		s = q; 
		q = q->next; 
	} 

 
	Node* head = s; 
	while (p != NULL && q != NULL) { 
		if (p->data < q->data) { 

		s->next = p; 
			p->prev = s; 
			s = s->next; 
			p = p->next; 
		} 
		else { 


			s->next = q; 
			q->prev = s; 
			s = s->next; 
			q = q->next; 
		} 
	} 

	if (p == NULL) { 
		s->next = q; 
		q->prev = s; 
	} 
	if (q == NULL) { 
		s->next = p; 
		p->prev = s; 
	} 


	return head; 
} 


Node* mergeAllList(Node* head[], int k) 
{ 
	Node* finalList = NULL; 
	for (int i = 0; i < k; i++) { 


		finalList = mergeList(finalList, head[i]); 
} 
	return finalList; 
} 


int main() 
{ 
	int k = 3; 
	Node* head[k]; 


	for (int i = 0; i < k; i++) { 
		head[i] = NULL; 
	} 

	append(&head[0], 1); 

	append(&head[0], 5); 

	append(&head[0], 9); 

 

	append(&head[1], 2); 

	append(&head[1], 3); 

	append(&head[1], 7); 

	append(&head[1], 12); 

	append(&head[2], 8); 

	append(&head[2], 11); 

	append(&head[2], 13); 

	append(&head[2], 18); 

	Node* finalList = mergeAllList(head, k); 


	printList(finalList); 

	return 0; 
} 
