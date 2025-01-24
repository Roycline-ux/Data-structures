#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;               // Data stored in the node
    struct Node* next;      // Pointer to the next node in the list
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {  // Check if memory allocation failed
        printf("Memory allocation failed!\n");
        exit(1);            // Exit if memory allocation failed
    }
    newNode->data = data;   // Initialize the data
    newNode->next = NULL;   // Initialize the next pointer to NULL
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data); // Create a new node
    
    // If the list is empty, make the 
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; 
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    }
    printf("\n");
}

struct Node* merge(struct Node* list1, struct Node* list2) {
    
    printf("\nFirst Sorted List: ");
    printList(list1);
    printf("Second Sorted List: ");
    printList(list2);
    
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    struct Node* mergedList = NULL; 
    struct Node* current = NULL;   
    
    if (list1->data <= list2->data) {
        mergedList = list1;
        list1 = list1->next;
    } else {
        mergedList = list2;
        list2 = list2->next;
    }
    
    current = mergedList
    
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next; 
    }
    
    
    if (list1 != NULL) {
        current->next = list1;
    }
    
    if (list2 != NULL) {
        current->next = list2;
    }
    
    
    printf("Merged Sorted List: ");
    printList(mergedList);
    
    return mergedList; 
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 
    insertEnd(&list1, 1);
    insertEnd(&list1, 3);
    insertEnd(&list1, 5);
    insertEnd(&list1, 7);
    
    
    insertEnd(&list2, 2);
    insertEnd(&list2, 4);
    insertEnd(&list2, 6);
    insertEnd(&list2, 8);
    
    struct Node* mergedList = merge(list1, list2);
    
    return 0;
}