#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at End
void insert() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Node inserted successfully.\n");
}

// Display List
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search Node
void search() {
    int key, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &key);

    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("%d not found in list.\n", key);
}

// Delete Node
void deleteNode() {
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);

    struct Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Node deleted.\n");
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insert();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}