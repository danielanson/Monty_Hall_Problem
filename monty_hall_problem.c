#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef MAX_TRIES
#define MAX_TRIES 10000000
#endif

int montyHall(int myDoor, int doors[]);
int printAll(int myDoor, int doors[], int mhChoice, int newDoor);
int switchDoors(int myDoor, int mhChoice);
int winner(int myDoor, int doors[]);

int main() {

    int r = 0, mh = 0, myDoor = 0, totalWins = 0, totalLosses = 0, newDoor = 0;
    srand(time(NULL));

    for(int i=0; i<MAX_TRIES; i++) {

        // start with an array all zeroes.
        // Pick a pseudo-random number 0, 1, or 2
        // fill that array index with a 1
        // the car is a 1, the goat is a 0.
        // Hence, 2 goats, 1 car.
        int doors[] = {0, 0, 0};
        r = rand() % 3;
        doors[r] = 1;

        // Randomly pick a door.
        myDoor = rand() % 3;

        // Monty Hall:
        // 1) picks a door that's not your door
        // 2) Always reveals a goat
        // 3) Must offer you the ability to switch
        //    your chosen door with the remaining door
        mh = montyHall(myDoor, doors);

        // Monty Hall asks if you want to switch doors,
        // after showing you a goat, you say, "Hell yeah!"
        newDoor = switchDoors(myDoor, mh); 
        if (winner(newDoor, doors)) {
            totalWins += 1;
        } else { 
            totalLosses += 1;
        }
        // printAll(myDoor, doors, mh, newDoor);
    }
    printf("Total Wins:    %d\n", totalWins);
    printf("Total Losses:  %d\n", totalLosses);
}

// A Monty Hall simulator algorithm
int montyHall(int door, int doors[]) {

    int r;
    while(1) {
        r = rand() % 3;
        if (r == door) {
            ;
        } else if (doors[r] == 1) {
            ;
        } else {
            return r;
        }
    }
}

int printAll(int myDoor, int doors[], int mhChoice, int newDoor) {

    printf("My door      : %d\n", myDoor);
    printf("All doors    : {%d, %d, %d}\n", doors[0], doors[1], doors[2]);
    printf("Monty's pick : %d\n", mhChoice);
    printf("New door     : %d\n", newDoor);
    printf("\n");
    return 0;
}

int switchDoors(int myDoor, int mhChoice) {

    int doors[] = {1, 1, 1}, newDoor;
    doors[myDoor] = 0;
    doors[mhChoice] = 0;
    if (doors[0]) { newDoor = 0; }
    if (doors[1]) { newDoor = 1; }
    if (doors[2]) { newDoor = 2; }
    return newDoor;
}

int winner(int myDoor, int doors[]) {

    return doors[myDoor];
}
