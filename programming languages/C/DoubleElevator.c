#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 40

int randomNumber(int min_num, int max_num);
void elevatorRun(int* currentFloor, int floorBetween, int direction, int bestElevator);
void drawFloors(int currentFloor[]);
void downFloor(int* currentFloor, int floorBetween, int bestElevator);
void upFloor(int* currentFloor, int floorBetween, int bestElevator);
int manageElevators(int* currentFloor, int choiceFloor);

void main(void) {

    int currentPlayerFloor = 1;
    int porra = randomNumber(1, 2);
    int currentElevator01Floor = randomNumber(5, 7);
    int currentElevator02Floor = randomNumber(3, 6);
    if(currentElevator02Floor == currentElevator01Floor) {
        if(porra == 1) { 
            currentElevator02Floor -= 1; 
        } else { 
            currentElevator02Floor += 1;
        }
    }

    int currentFloor[3];
    currentFloor[0] = currentPlayerFloor;
    currentFloor[1] = currentElevator01Floor;
    currentFloor[2] = currentElevator02Floor;

    int choiceFloor = 0, inputChoice, elevatorReady = 0;
    bool running = true;

    while(running == true) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        drawFloors(currentFloor);
        printf("\n");
        printf("\nOque deseja fazer?\n");
        printf("Digite 1 para chamar o elevador\n");
        printf("Digite 2 para checar seu andar atual\n");
        printf("Digite 3 para sair do programa\n");
        printf("Digite: ");
        scanf("%d", &inputChoice);

        switch(inputChoice) {
            case 1:
                int elevatorReady = manageElevators(currentFloor, choiceFloor);
                printf("\n O elevador está vindo");
                if(elevatorReady == 1) {
                    printf("\nPara qual andar você deseja ir?\n");
                    printf("Digite: ");
                    scanf("%d", &choiceFloor);
                    while(choiceFloor > 15 || choiceFloor <= 0){
                        printf("\n%d não é um andar selecionável, digite novamente: ", choiceFloor);
                        scanf("%d", &choiceFloor);
                    }
                }
                break;
            case 2:
                printf("\nSeu andar atual é %d", currentFloor[0]);
                break;
            default: 
                printf("tomanocu");
        }
    }
}

void elevatorRun(int* currentFloor, int floorBetween, int direction, int bestElevator){
    for(int i = 0; i <= floorBetween; i ++){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        
        drawFloors(currentFloor);
        
        if(direction == 1){
            currentFloor[0] += 1;
        } else {
            currentFloor[0] -= 1;
        }
        currentFloor[bestElevator] = currentFloor[0];
        
        sleep(1);
    }
}

void downFloor(int* currentFloor, int floorBetween, int bestElevator){
    floorBetween *= 1;
    int direction = 2;
    elevatorRun(currentFloor, floorBetween, direction, bestElevator);

    currentFloor[0] += 1;
    currentFloor[bestElevator] = currentFloor[0];
    printf("\nVocê chegou ao andar %d. Por favor saia do elevador.\n", currentFloor[0]);
    sleep(2);
}
void upFloor(int* currentFloor, int floorBetween, int bestElevator){
    int direction = 1;
    elevatorRun(currentFloor, floorBetween, direction, bestElevator);

    currentFloor[0] -= 1;
    currentFloor[bestElevator] = currentFloor[0];
    printf("\nVocê chegou ao andar %d. Por favor saia do elevador.\n", currentFloor[0]);
    sleep(2);
}

int manageElevators(int* currentFloor, int choiceFloor) {
    int floorBetween, floorBetweenElevator01, floorBetweenElevator02, bestElevator;
    if(choiceFloor == 0) {
        floorBetweenElevator01 = currentFloor[0] - currentFloor[1];
        floorBetweenElevator02 = currentFloor[0] - currentFloor[2];

        if(floorBetweenElevator01 < floorBetweenElevator02) {
            bestElevator = 1;
            floorBetween = floorBetweenElevator01;
        } else {
            bestElevator = 2;
            floorBetween = floorBetweenElevator02;
        }
    } else {
        floorBetween = choiceFloor - currentFloor[0];
    }

    if(floorBetween > 0) {
        upFloor(currentFloor, floorBetween, bestElevator);
    } else {
        downFloor(currentFloor, floorBetween, bestElevator);
    }

    return 1;
}

void drawFloors(int currentFloor[]) {
    int FloorsQuantity = 7;

    for(int j = FloorsQuantity; j > 0; j--){
        
        if(j == currentFloor[0] && j == currentFloor[1] && j == currentFloor[2]) {
            printf("\n|x|  |x| %d - Você está neste andar.\n", currentFloor[0]);
        } else if(j == currentFloor[0] && j == currentFloor[1]) {
            printf("\n| |  |x| %d - Você está neste andar. \n", currentFloor[0]);
        } else if(j == currentFloor[0] && j == currentFloor[2]) {
            printf("\n|x|  | | %d - Você está neste andar. \n", currentFloor[0]);
        } else if(j == currentFloor[0]) {
            printf("\n| |  | | %d - Você está neste andar.\n", currentFloor[0]);
        } else if(j == currentFloor[1] && j == currentFloor[2]) {
            printf("\n|x|  |x| %d\n", j);
        } else if(j == currentFloor[1]) {
            printf("\n| |  |x| %d", j);
        } else if(j == currentFloor[2]) {
            printf("\n|x|  | | %d", j);
        } else {
            printf("\n| |  | | %d", j);
        }

    }

}

int randomNumber(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}
