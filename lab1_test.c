//
// Created by janin on 4/14/2020.
//
#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) {
    printf(1, "\n Begin testing program \n");
    int waitpid_test(void); //declare
    waitpid_test();
    exit(0);
    return 0;
}

int waitpid_test(void) {
    int return_pid, exit_status;
    int arr[3] = {0, 0, 0}; //pid array
    int i;

    for (i = 0; i < 3; i++) {
        arr[i] = fork();

        if(arr[i] == 0) { //only children enter this segment
            printf(1, "child process -- pid %d and exit status %d\n", getpid(), 0);
            exit(0); //exit
        }
    }
    //only parents here -- waiting for pid of arr[2], arr[3], then arr[1]
    sleep(5); //buffer
    printf(1, "parent process -- waiting for child of pid %d\n", arr[1]);
    return_pid = waitpid(arr[1], &exit_status, 0);
    printf(1, "child of pid %d exited with status %d\n", return_pid, exit_status);

    sleep(5); //buffer
    printf(1, "parent process -- waiting for child of pid %d\n", arr[2]);
    return_pid = waitpid(arr[2], &exit_status, 0);
    printf(1, "child of pid %d exited with status %d\n", return_pid, exit_status);

    sleep(5); //buffer
    printf(1, "parent process -- waiting for child of pid %d\n", arr[0]);
    return_pid = waitpid(arr[0], &exit_status, 0);
    printf(1, "child of pid %d exited with status %d\n", return_pid, exit_status);

    return 0;
}
