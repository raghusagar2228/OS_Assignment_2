#include <stdio.h>
#include <string.h>

#define MAX 100

struct Process {
    int pid;
    char name[30];
    int priority;
    char state[20];
};

int main() {
    struct Process p[MAX];
    int n, choice, i, pid, found;
    char searchState[20], newState[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Enter process details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of Process %d\n", i + 1);

        printf("Enter PID: ");
        scanf("%d", &p[i].pid);

        printf("Enter Process Name: ");
        scanf("%s", p[i].name);

        printf("Enter Priority: ");
        scanf("%d", &p[i].priority);

        printf("Enter State (New/Ready/Running/Waiting/Terminated): ");
        scanf("%s", p[i].state);
    }

    do {
        printf("\n========== PROCESS MANAGEMENT ==========\n");
        printf("1. Display all process details\n");
        printf("2. Display process with highest priority\n");
        printf("3. Display processes in a particular state\n");
        printf("4. Change state of a process\n");
        printf("5. Display current state of all processes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\n----- All Process Details -----\n");
                printf("PID\tName\t\tPriority\tState\n");

                for (i = 0; i < n; i++) {
                    printf("%d\t%-15s%d\t\t%s\n",
                           p[i].pid,
                           p[i].name,
                           p[i].priority,
                           p[i].state);
                }
                break;

            case 2: {
                int highest = 0;

                for (i = 1; i < n; i++) {
                    if (p[i].priority > p[highest].priority) {
                        highest = i;
                    }
                }

                printf("\n----- Highest Priority Process -----\n");
                printf("PID      : %d\n", p[highest].pid);
                printf("Name     : %s\n", p[highest].name);
                printf("Priority : %d\n", p[highest].priority);
                printf("State    : %s\n", p[highest].state);

                break;
            }

            case 3:
                printf("\nEnter state to search: ");
                scanf("%s", searchState);

                found = 0;

                printf("\nProcesses in %s state:\n", searchState);

                for (i = 0; i < n; i++) {
                    if (strcmp(p[i].state, searchState) == 0) {
                        printf("PID: %d\tName: %s\tPriority: %d\n",
                               p[i].pid,
                               p[i].name,
                               p[i].priority);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("No process found in this state.\n");
                }

                break;

            case 4:
                printf("\nEnter PID of process: ");
                scanf("%d", &pid);

                found = 0;

                for (i = 0; i < n; i++) {
                    if (p[i].pid == pid) {

                        printf("Current State: %s\n", p[i].state);

                        printf("Enter new state: ");
                        scanf("%s", newState);

                        strcpy(p[i].state, newState);

                        printf("State changed successfully!\n");
                        printf("New State: %s\n", p[i].state);

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Process with PID %d not found.\n", pid);
                }

                break;

            case 5:
                printf("\n----- Current State of All Processes -----\n");
                printf("PID\tName\t\tState\n");

                for (i = 0; i < n; i++) {
                    printf("%d\t%-15s%s\n",
                           p[i].pid,
                           p[i].name,
                           p[i].state);
                }

                break;

            case 6:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
