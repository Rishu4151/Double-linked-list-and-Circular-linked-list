#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int value;
    struct Node *previous, *nextNode;
};
struct Node* createDLL(int count) 
{
    if (count <= 0) return NULL;

    struct Node *headNode = NULL, *currentNode = NULL, *newNode;
    for (int i = 1; i <= count; i++) 
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) return headNode;

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->value);
        newNode->nextNode = NULL;

        if (!headNode) 
        {
            newNode->previous = NULL;
            headNode = currentNode = newNode;
        } 
        else 
        {
            newNode->previous = currentNode;
            currentNode->nextNode = newNode;
            currentNode = newNode;
        }
    }
    return headNode;
}
void displayDLL(struct Node *headNode)
{
    struct Node *currentNode = headNode;
    if (!headNode) 
    {
        printf("The list is empty.\n");
        return;
    }
    printf("Forward: ");
    while (currentNode) 
    {
        printf("%d <-> ", currentNode->value);
        if (!currentNode->nextNode) break;
        currentNode = currentNode->nextNode;
    }
    printf("NULL\nBackward: ");

    while (currentNode) 
    {
        printf("%d <-> ", currentNode->value);
        currentNode = currentNode->previous;
    }
    printf("NULL\n");
}
struct Node* insertAtEnd(struct Node* headNode, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return headNode;
    
    newNode->value = value;
    newNode->nextNode = NULL;

    if (!headNode) return newNode;

    struct Node* currentNode = headNode;
    while (currentNode->nextNode) currentNode = currentNode->nextNode;

    currentNode->nextNode = newNode;
    newNode->previous = currentNode;
    return headNode;
}
struct Node* deleteNode(struct Node* headNode, int key) 
{
    struct Node *currentNode = headNode;
    while (currentNode && currentNode->value != key) currentNode = currentNode->nextNode;

    if (!currentNode) return headNode;

    if (currentNode->previous) currentNode->previous->nextNode = currentNode->nextNode;
    if (currentNode->nextNode) currentNode->nextNode->previous = currentNode->previous;

    if (currentNode == headNode) headNode = currentNode->nextNode;
    free(currentNode);
    return headNode;
}
int main() 
{
    int nodeCount, value, key;
    struct Node *headNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &nodeCount);
    headNode = createDLL(nodeCount);
    displayDLL(headNode);

    printf("Enter value to insert at end: ");
    scanf("%d", &value);
    headNode = insertAtEnd(headNode, value);
    displayDLL(headNode);

    printf("Enter value to delete: ");
    scanf("%d", &key);
    headNode = deleteNode(headNode, key);
    displayDLL(headNode);

    return 0;
}