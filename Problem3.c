#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int value;
    struct Node *nextNode;
};
struct Node* createCircularLinkedList(int count) 
{
    if (count <= 0) return NULL;
    struct Node *headNode = NULL, *currentNode = NULL, *newNode;
    for (int i = 1; i <= count; i++) 
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) return headNode;

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->value);

        if (!headNode) 
        {
            headNode = newNode;
            newNode->nextNode = headNode;
            currentNode = headNode;
        } 
        else 
        {
            currentNode->nextNode = newNode;
            newNode->nextNode = headNode;
            currentNode = newNode;
        }
    }
    return headNode;
}
void displayCircularLinkedList(struct Node *headNode) 
{
    if (!headNode) 
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node *currentNode = headNode;
    printf("Circular Linked List: ");
    do 
    {
        printf("%d -> ", currentNode->value);
        currentNode = currentNode->nextNode;
    } 
    while (currentNode != headNode);
    printf("(Back to Head)\n");
}
int main() 
{
    int nodeCount;
    struct Node *headNode = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodeCount);
    headNode = createCircularLinkedList(nodeCount);
    displayCircularLinkedList(headNode);
    return 0;
}