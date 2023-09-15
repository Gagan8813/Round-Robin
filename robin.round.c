#include <stdio.h>

#define MAX_PROCESS 10

struct Process {
    int id;
    int burstTime;
    int remainingTime;
};

int main() {
    int quantum;
    int numProcesses;
    struct Process processes[MAX_PROCESS];

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].id = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    int totalExecutionTime = 0;
    while (1) {
        int allProcessesCompleted = 1;

        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].remainingTime > 0) {
                allProcessesCompleted = 0;

                if (processes[i].remainingTime <= quantum) {
                    totalExecutionTime += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                } else {
                    totalExecutionTime += quantum;
                    processes[i].remainingTime -= quantum;
                }

                printf("Process %d executed for %d units of time\n", processes[i].id, totalExecutionTime);
            }
        }

        if (allProcessesCompleted) {
            break;
        }
    }

    return 0;
}

