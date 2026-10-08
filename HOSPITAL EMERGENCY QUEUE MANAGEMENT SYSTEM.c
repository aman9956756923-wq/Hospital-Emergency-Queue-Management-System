#include <stdio.h>
#include <string.h>

#define MAX 50

struct Patient {
    int id;
    char name[50];
    int age;
    char problem[100];
};

struct Patient queue[MAX];

int front = -1;
int rear = -1;

// Add Patient
void addPatient() {
    if (rear == MAX - 1) {
        printf("\nQueue is Full! Cannot add more patients.\n");
        return;
    }

    struct Patient p;

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Problem: ");
    scanf(" %[^\n]", p.problem);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = p;

    printf("\nPatient added successfully!\n");
}

// Treat Patient
void treatPatient() {
    if (front == -1 || front > rear) {
        printf("\nNo patients in the queue.\n");
        return;
    }

    printf("\nPatient being treated:\n");
    printf("ID      : %d\n", queue[front].id);
    printf("Name    : %s\n", queue[front].name);
    printf("Age     : %d\n", queue[front].age);
    printf("Problem : %s\n", queue[front].problem);

    front++;

    if (front > rear) {
        front = -1;
        rear = -1;
    }

    printf("\nPatient treatment started.\n");
}

// Display Queue
void displayQueue() {
    if (front == -1 || front > rear) {
        printf("\nNo patients waiting.\n");
        return;
    }

    printf("\n========== Emergency Queue ==========\n");

    for (int i = front; i <= rear; i++) {
        printf("\nPatient %d\n", i - front + 1);
        printf("ID      : %d\n", queue[i].id);
        printf("Name    : %s\n", queue[i].name);
        printf("Age     : %d\n", queue[i].age);
        printf("Problem : %s\n", queue[i].problem);
    }

    printf("\n=====================================\n");
}

// Search Patient
void searchPatient() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty.\n");
        return;
    }

    int id;
    int found = 0;

    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);

    for (int i = front; i <= rear; i++) {
        if (queue[i].id == id) {
            printf("\nPatient Found!\n");
            printf("ID      : %d\n", queue[i].id);
            printf("Name    : %s\n", queue[i].name);
            printf("Age     : %d\n", queue[i].age);
            printf("Problem : %s\n", queue[i].problem);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nPatient not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n\n===== HOSPITAL EMERGENCY QUEUE =====\n");
        printf("1. Add Patient\n");
        printf("2. Treat Patient\n");
        printf("3. Display Queue\n");
        printf("4. Search Patient\n");
        printf("5. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                treatPatient();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                searchPatient();
                break;

            case 5:
                printf("\nThank you!\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}