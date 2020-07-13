#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
int countNodes(Node *head);

Node *sortedListToBSTRecur(Node **head_ref, int n);
Node *sortedListToBST(Node *head)
{
    int n = countNodes(head);
    return sortedListToBSTRecur(&head, n);
}
Node *sortedListToBSTRecur(Node **head_ref, int n)
{
    
    if (n <= 0)
        return NULL;
    Node *left = sortedListToBSTRecur(head_ref, n / 2);
    Node *root = *head_ref;
    root->prev = left;
    *head_ref = (*head_ref)->next;
    root->next = sortedListToBSTRecur(head_ref, n - n / 2 - 1);

    return root;
}
int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
void preOrder(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->prev);
    preOrder(node->next);
}


int main()
{
    Node *head = NULL;
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given Linked List\n";
    printList(head);
    Node *root = sortedListToBST(head);
    cout << "\nPreOrder Traversal of constructed BST \n ";
    preOrder(root);

    return 0;
}

