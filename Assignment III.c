#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a doubly linked list
struct Node {
    int data;               // Data stored in the node
    struct Node* prev;      // Pointer to the previous node in the list
    struct Node* next;      // Pointer to the next node in the list
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {  // Check if memory allocation failed
        printf("Memory allocation failed!\n");
        exit(1);            // Exit if memory allocation failed
    }
    newNode->data = data;   // Initialize the data
    newNode->prev = NULL;   // Initialize the previous pointer to NULL
    newNode->next = NULL;   // Initialize the next pointer to NULL
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNode(data);
    
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the end of the list
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;    // Insert the new node at the end
    newNode->prev = temp;    // Set the previous pointer of the new node
}

// Function to reverse a doubly linked list
struct Node* reverseList(struct Node* head) {
    struct Node* temp = NULL;    // Temporary pointer for swapping
    struct Node* current = head; // Pointer to traverse the list
    
    // Swap next and prev for all nodes of the doubly linked list
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    // Before changing head, check for the cases like empty list and list with only one node
    if (temp != NULL) {
        head = temp->prev;
    }
    
    return head;
}

// Function to add two doubly linked lists representing numbers
struct Node* addLists(struct Node* head1, struct Node* head2) {
    // Reverse both lists to make the addition easier
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    
    struct Node* result = NULL; // Pointer to the head of the result list
    struct Node* temp1 = head1; // Pointer to traverse the first list
    struct Node* temp2 = head2; // Pointer to traverse the second list
    int carry = 0;              // Variable to store carry-over during addition
    
    // Traverse both lists and add corresponding digits
    while (temp1 != NULL || temp2 != NULL) {
        int sum = carry;
        
        // Add data from the first list if available
        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        
        // Add data from the second list if available
        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        
        carry = sum / 10;   // Calculate the carry for the next digit
        sum = sum % 10;     // Get the single digit sum
        
        // Insert the sum digit at the end of the result list
        insertEnd(&result, sum);
    }
    
    // If there is a carry left, add it to the result
    if (carry > 0) {
        insertEnd(&result, carry);
    }
    
    // Reverse the result list to get the final sum
    result = reverseList(result);
    
    return result;
}

// Function to print a doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) { // Traverse the list
        printf("%d", temp->data); // Print the data of each node
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    
    // Create the first doubly linked list: 3 -> 5 -> 0 (representing 350)
    insertEnd(&list1, 3);
    insertEnd(&list1, 5);
    insertEnd(&list1, 0);
    
    // Create the second doubly linked list: 2 -> 2 -> 5 (representing 225)
    insertEnd(&list2, 2);
    insertEnd(&list2, 2);
    insertEnd(&list2, 5);
    
    // Print input lists
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    
    // Add the two lists
    struct Node* sumList = addLists(list1, list2);
    
    // Print the result
    printf("Sum List: ");
    printList(sumList);
    
    return 0;
}
