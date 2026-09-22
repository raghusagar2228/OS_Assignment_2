#include <stdio.h>
#include <string.h>

#define MAX 100

struct Process {
    int pid;
    char name[50];
    int priority;
    char state[20];
};

int main() {
    struct Process p[MAX];
    int n, choice, i, pid, found;
    char searchState[20];
    char newState[20];

    // Enter number of processes
    printf("Enter number of customer support tickets: ");
    scanf("%d", &n);

    // Enter process/ticket details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of Ticket %d\n", i + 1);

        printf("Enter Ticket ID: ");
        scanf("%d", &p[i].pid);

        printf("Enter Issue: ");
        scanf("%s", p[i].name);

        printf("Enter Priority (1 = Highest): ");
        scanf("%d", &p[i].priority);

        printf("Enter State (New/Ready/Running/Waiting/Terminated): ");
        scanf("%s", p[i].state);
    }

    // Menu
    do {
        printf("\n============================================\n");
        printf("     CUSTOMER SUPPORT TICKET SYSTEM\n");
        printf("============================================\n");
        printf("1. Display all ticket details\n");
        printf("2. Display highest priority ticket\n");
        printf("3. Display tickets in a particular state\n");
        printf("4. Change state of a selected ticket\n");
        printf("5. Display current state of all tickets\n");
        printf("6. Exit\n");
        printf("============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // 1. Display all ticket details
            case 1:
                printf("\n------------- ALL TICKET DETAILS -------------\n");
                printf("Ticket ID\tIssue\t\tPriority\tState\n");

                for (i = 0; i < n; i++) {
                    printf("%d\t\t%-15s%d\t\t%s\n",
                           p[i].pid,
                           p[i].name,
                           p[i].priority,
                           p[i].state);
                }

                break;

            // 2. Display highest priority ticket
            case 2: {
                int highest = 0;

                // Lower number = higher priority
                for (i = 1; i < n; i++) {
                    if (p[i].priority < p[highest].priority) {
                        highest = i;
                    }
                }

                printf("\n---------- HIGHEST PRIORITY TICKET ----------\n");
                printf("Ticket ID : %d\n", p[highest].pid);
                printf("Issue     : %s\n", p[highest].name);
                printf("Priority  : %d\n", p[highest].priority);
                printf("State     : %s\n", p[highest].state);

                break;
            }

            // 3. Display tickets in a particular state
            case 3:
                printf("\nEnter state to search: ");
                scanf("%s", searchState);

                found = 0;

                printf("\n---------- TICKETS IN %s STATE ----------\n",
                       searchState);

                for (i = 0; i < n; i++) {
                    if (strcmp(p[i].state, searchState) == 0) {

                        printf("Ticket ID: %d\tIssue: %s\tPriority: %d\n",
                               p[i].pid,
                               p[i].name,
                               p[i].priority);

                        found = 1;
                    }
                }

                if (found == 0) {
                    printf("No tickets found in this state.\n");
                }

                break;

            // 4. Change state of selected ticket
            case 4:
                printf("\nEnter Ticket ID: ");
                scanf("%d", &pid);

                found = 0;

                for (i = 0; i < n; i++) {

                    if (p[i].pid == pid) {

                        printf("Current State: %s\n", p[i].state);

                        printf("Enter new state: ");
                        scanf("%s", newState);

                        strcpy(p[i].state, newState);

                        printf("\nState changed successfully!\n");
                        printf("Ticket ID: %d\n", p[i].pid);
                        printf("New State: %s\n", p[i].state);

                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("Ticket with ID %d not found.\n", pid);
                }

                break;

            // 5. Display current state of all tickets
            case 5:
                printf("\n---------- CURRENT STATE OF ALL TICKETS ----------\n");
                printf("Ticket ID\tIssue\t\tState\n");

                for (i = 0; i < n; i++) {
                    printf("%d\t\t%-15s%s\n",
                           p[i].pid,
                           p[i].name,
                           p[i].state);
                }

                break;

            // 6. Exit
            case 6:
                printf("\nExiting Customer Support Ticket System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
