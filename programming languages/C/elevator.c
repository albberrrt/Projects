#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void drawFloors(currentFloor){
    int FloorsQuantity = 7;
    
    for(int j = FloorsQuantity; j > 0; j--){
        if(j == currentFloor){
            printf("|| Andar %d - Você está aqui.\n", currentFloor);
        } else {
            printf("|| Andar %d\n", j);
        }
    }
}

int elevatorRun(floorBetween, currentFloor, direction){
    for(int i = 0; i <= floorBetween; i ++){
        printf("\n\n\n\n\n\n\n\n\n\n");
        
        drawFloors(currentFloor);
        
        if(direction == 1){
            currentFloor += 1;
        } else {
            currentFloor -= 1;
        }
        
        sleep(1);
    }
    return currentFloor;
}

int downFloor(int currentFloor, int floorBetween){
    floorBetween *= -1;
    int direction = 2;
    currentFloor = elevatorRun(floorBetween, currentFloor, direction);
    
    currentFloor += 1;
    printf("\nVocê chegou ao andar %d. Por favor saia do elevador.\n", currentFloor);
    sleep(2);
    return currentFloor;
}

int upFloor(int currentFloor, int floorBetween) {
    int direction = 1;
    currentFloor = elevatorRun(floorBetween, currentFloor, direction);
    
    currentFloor -= 1;
    printf("\nVocê chegou ao andar %d. Por favor saia do elevador.\n", currentFloor);
    sleep(2);
    return currentFloor;
}

void checkCurrentFloor(int currentFloor) {
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\nSeu andar atual é %d.\n", currentFloor);
    sleep(2);
}

int manageElevator(int choiceFloor, int currentFloor){
    int floorBetween = choiceFloor - currentFloor;
    if(floorBetween > 0){
        currentFloor = upFloor(currentFloor, floorBetween);
    } else {
        currentFloor = downFloor(currentFloor, floorBetween);
    }
    return currentFloor;
}

int main() {
    int currentFloor = 1;
    int choiceFloor;
    int inputChoice;
    bool running = true;
    
    while(running = true){
        
        printf("\n\n\n\n\n\n\n\n\n\n");
        drawFloors(currentFloor);
        printf("\n");
        printf("\nOque deseja fazer?\n");
        printf("Digite 1 para usar o elevador\n");
        printf("Digite 2 para checar seu andar atual\n");
        printf("Digite 3 para sair do programa\n");
        printf("Digite: ");
        scanf("%d", &inputChoice);
        
        switch(inputChoice) {
            case 1: 
                printf("\nPara qual andar você deseja ir?\n");
                printf("Digite: ");
                scanf("%d", &choiceFloor);
                while(choiceFloor > 7 || choiceFloor <= 0){
                    printf("\n%d não é um andar selecionável, digite novamente: ");
                    scanf("%d", &choiceFloor);
                }
                currentFloor = manageElevator(choiceFloor, currentFloor);
                
                break;
            case 2:
                checkCurrentFloor(currentFloor);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("é oq");
        }
    }
    return 0;
} 