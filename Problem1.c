#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int value;
    struct Node *previous, *nextNode;
};

struct Node* initializeDLL(int count) 
{
    if (count <= 0) 
        return NULL;

    struct Node *headNode = NULL, *currentNode = NULL, *newNode = NULL;
    printf("Enter data for node 1: ");
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) 
        return NULL;

    scanf("%d", &newNode->value);
    newNode->previous = newNode->nextNode = NULL;
    headNode = currentNode = newNode;

    for (int index = 2; index <= count; index++) 
    {
        printf("Enter data for node %d: ", index);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) 
            return NULL;

        scanf("%d", &newNode->value);
        newNode->previous = currentNode;
        newNode->nextNode = NULL;
        currentNode->nextNode = newNode;
        currentNode = newNode;
    }
    return headNode;
}

void displayDLL(struct Node *headNode) 
{
    if (!headNode) 
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *currentNode = headNode;
    while (currentNode) 
    {
        printf("%d <-> ", currentNode->value);
        currentNode = currentNode->nextNode;
    }
    printf("NULL\n");
}

int main() 
{
    int nodeCount;
    struct Node *headNode = NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodeCount);
    headNode = initializeDLL(nodeCount);
    displayDLL(headNode);
    return 0;
}