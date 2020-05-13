//
// Created by janin on 5/12/2020.
//

#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[]) {
    setprior(5);

    int i, j;
    //int turnaround, wait; //TODO
    for(i = 0; i < 4500; i++) {
        asm("nop"); //assembly instruction to do nothing
        for(j = 0; j < 4500; j++) {
            asm("nop");
        }
    }
    printf(1, "Program 3 finished! \n\n");
    exit(0);
    return 0;
}