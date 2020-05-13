//
// Created by janin on 5/13/2020.
//

#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[]) {
    int i, j;
    int p1, p2, p3;

    p1 = fork();
    if (!p1) { //in first child
        for (i = 0; i < 2500; i++) {
            asm("nop");
            for (j = 0; j < 2500; j++) {
                asm("nop");
            }
        }
        //exit(0);

        printf(1, "Child 1 finished!\n");
        printf(1, "Ending priority: %d\n", getprior());
        printf(1, "Turnaround time: %d\n", getturntime());
        printf(1, "Wait time: %d\n", getwaittime());
    }
    else { //in parent
        p2 = fork();
        if (!p2) { //in second child
            for (i = 0; i < 2500; i++) {
                asm("nop");
                for (j = 0; j < 2500; j++) {
                    asm("nop");
                }
            }
            //exit(0);
            printf(1, "Child 2 finished!\n");
            printf(1, "Ending priority: %d\n", getprior());
            printf(1, "Turnaround time: %d\n", getturntime());
            printf(1, "Wait time: %d\n", getwaittime());
        }
        else {
            p3 = fork();
            if (!p3) { //in third child
                for (i = 0; i < 2500; i++) {
                    asm("nop");
                    for (j = 0; j < 2500; j++) {
                        asm("nop");
                    }
                }
                //exit(0);
                printf(1, "Child 2 finished!\n");
                printf(1, "Ending priority: %d\n", getprior());
                printf(1, "Turnaround time: %d\n", getturntime());
                printf(1, "Wait time: %d\n", getwaittime());
            }
        }
    }
    setprior(10);
    for (i = 0; i < 2500; i++) {
        asm("nop");
        for (j = 0; j < 2500; j++) {
            asm("nop");
        }
    }
    printf(1, "Program finished!\n");
    printf(1, "Ending priority: %d\n", getprior());
    printf(1, "Turnaround time: %d\n", getturntime());
    printf(1, "Wait time: %d\n", getwaittime());
    printf(1, "-----------------\n");
    exit(0);
    return 0;
}