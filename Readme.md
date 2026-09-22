Assignment 2 - Process Management Simulation

Operating Systems

A menu-driven C program that simulates basic process management
operations such as storing process details, checking process priority,
searching by process state, and changing process states.

1. Objective

The program allows the user to:

Enter the details of n processes.

Display all process details.

Display the process with the highest priority.

Display processes in a particular state.

Change the state of a selected process.

Display the current state of all processes.

Priority rule: A lower numerical value represents a higher
priority.
For example, priority 1 is higher than priority 2.

2. Process Details

Each process contains the following information:

Field          Description

PID            Unique Process ID
Process Name   Name of the process
Priority       Priority assigned to the process
State          Current state of the process

Supported States

New

Ready

Running

Waiting

Terminated

3. Real-Life Scenario - Customer Support Ticket System

A customer support ticket system can be used as a real-life example of
process management.

Each customer complaint is treated as a process:

Operating System Concept   Customer Support System

Process                    Customer support ticket
PID                        Ticket ID
Process Name               Customer issue
Priority                   Urgency of the issue
New                        Newly created ticket
Ready                      Ticket waiting for a support agent
Running                    Agent is handling the ticket
Waiting                    Waiting for customer information
Terminated                 Issue resolved / ticket closed

Example

Suppose a company receives:

Ticket 101 - Payment Failure - Priority 1 - Ready
Ticket 102 - Login Problem   - Priority 3 - Running
Ticket 103 - Address Change  - Priority 5 - Waiting

Since a lower number means higher priority, Ticket 101 has the
highest priority.

A ticket can follow a lifecycle such as:

New → Ready → Running → Waiting → Running → Terminated

4. Program Menu

============================================
          PROCESS MANAGEMENT SYSTEM
============================================
1. Display all process details
2. Display process with highest priority
3. Display processes in a particular state
4. Change state of a selected process
5. Display current state of all processes
6. Exit
============================================

5. Algorithm

Read the number of processes.

Read the PID, process name, priority, and state of each process.

Store the information using a structure.

Display the process-management menu.

If the user selects option 1, display all process details.

If option 2 is selected, compare priorities and select the process
with the smallest priority number.

If option 3 is selected, search and display processes having the
requested state.

If option 4 is selected, find the process using its PID and update
its state.

If option 5 is selected, display the current state of every process.

Continue until the user selects Exit.

6. C Program

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
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Enter process details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of Process %d\n", i + 1);

        printf("Enter PID: ");
        scanf("%d", &p[i].pid);

        printf("Enter Process Name: ");
        scanf("%s", p[i].name);

        printf("Enter Priority (1 = Highest): ");
        scanf("%d", &p[i].priority);

        printf("Enter State (New/Ready/Running/Waiting/Terminated): ");
        scanf("%s", p[i].state);
    }

    // Menu
    do {
        printf("\n============================================\n");
        printf("          PROCESS MANAGEMENT SYSTEM\n");
        printf("============================================\n");
        printf("1. Display all process details\n");
        printf("2. Display process with highest priority\n");
        printf("3. Display processes in a particular state\n");
        printf("4. Change state of a selected process\n");
        printf("5. Display current state of all processes\n");
        printf("6. Exit\n");
        printf("============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\n------------- ALL PROCESS DETAILS -------------\n");
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

                // Lower number means higher priority
                for (i = 1; i < n; i++) {
                    if (p[i].priority < p[highest].priority) {
                        highest = i;
                    }
                }

                printf("\n---------- HIGHEST PRIORITY PROCESS ----------\n");
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

                printf("\n---------- PROCESSES IN %s STATE ----------\n",
                       searchState);

                for (i = 0; i < n; i++) {
                    if (strcmp(p[i].state, searchState) == 0) {

                        printf("PID: %d\tName: %s\tPriority: %d\n",
                               p[i].pid,
                               p[i].name,
                               p[i].priority);

                        found = 1;
                    }
                }

                if (found == 0) {
                    printf("No processes found in this state.\n");
                }

                break;

            case 4:
                printf("\nEnter PID of the process: ");
                scanf("%d", &pid);

                found = 0;

                for (i = 0; i < n; i++) {

                    if (p[i].pid == pid) {

                        printf("Current State: %s\n", p[i].state);

                        printf("Enter new state: ");
                        scanf("%s", newState);

                        strcpy(p[i].state, newState);

                        printf("\nState changed successfully!\n");
                        printf("PID       : %d\n", p[i].pid);
                        printf("New State : %s\n", p[i].state);

                        found = 1;
                        break;
                    }
                }

                if (found == 0) {
                    printf("Process with PID %d not found.\n", pid);
                }

                break;

            case 5:
                printf("\n---------- CURRENT STATE OF ALL PROCESSES ----------\n");
                printf("PID\tName\t\tState\n");

                for (i = 0; i < n; i++) {
                    printf("%d\t%-15s%s\n",
                           p[i].pid,
                           p[i].name,
                           p[i].state);
                }

                break;

            case 6:
                printf("\nExiting Process Management System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

7. Sample Input

Enter number of processes: 3

Enter details of Process 1
Enter PID: 101
Enter Process Name: Process1
Enter Priority (1 = Highest): 3
Enter State: Ready

Enter details of Process 2
Enter PID: 102
Enter Process Name: Process2
Enter Priority (1 = Highest): 1
Enter State: Running

Enter details of Process 3
Enter PID: 103
Enter Process Name: Process3
Enter Priority (1 = Highest): 5
Enter State: Waiting

8. Sample Highest Priority Output

---------- HIGHEST PRIORITY PROCESS ----------

PID      : 102
Name     : Process2
Priority : 1
State    : Running

9. Technologies Used

Language: C

Concepts: Structures, arrays, strings, loops, conditional
statements, switch-case

Topic: Operating Systems - Process Management

10. Conclusion

This project demonstrates the basic management of process information
through a menu-driven C program. It shows how processes can be stored,
displayed, searched based on state, prioritized, and updated. The
Customer Support Ticket System provides a practical real-life analogy
for understanding process IDs, priorities, and state transitions.

11. How to Run

Using GCC

gcc process_management.c -o process_management

Then run:

./process_management

Windows

gcc process_management.c -o process_management.exe
process_management.exe

12. Author

Assignment 2 - Operating Systems
