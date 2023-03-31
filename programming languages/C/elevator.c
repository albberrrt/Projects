// Nome: Elevator run
// Objetivo: O objetivo do programa é simular um elevador simples através do console.
// Desenvolvedor: Albert Smaczylo
// Criação: 03/03/2023

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 40

// Inicialização das funções

void drawFloors(int currentFloor); // Função que desenha os elevadores na tela 

int elevatorRun(int floorBetween, int currentFloor, int direction); // Função que gerencia o funcionamento do elevador quando está mudando de andar 

int downFloor(int currentFloor, int floorBetween); // Função que faz o elevador descer

int upFloor(int currentFloor, int floorBetween); // Função que faz o elevador subir

void checkCurrentFloor(int currentFloor); // Função que checa qual o andar atual do Usuário

int manageElevator(int choiceFloor, int currentFloor); // Função que gerencia o comando que vai dar para o elevador(se vai subir, descer, andares entre andar atual e escolha)

// Função Main
void main() {
    int currentFloor = 1;
    int choiceFloor;
    int inputChoice;
    bool running = true;
    
    while(running = true){
        
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        drawFloors(currentFloor);
        printf("\n");
        
        // Escolhas do usuário
        printf("\nOque deseja fazer?\n");
        printf("Digite 1 para usar o elevador\n");
        printf("Digite 2 para checar seu andar atual\n");
        printf("Digite 3 para sair do programa\n");
        printf("Digite: ");
        scanf("%d", &inputChoice);
        
        // Switch que controla as ações com base na escolha do usuário
        switch(inputChoice) {
            
            //Case 1: Usar o elevador
            case 1: 
                printf("\nPara qual andar você deseja ir?\n");
                printf("Digite: ");
                scanf("%d", &choiceFloor);
                while(choiceFloor > 15 || choiceFloor <= 0){
                    printf("\n%d não é um andar selecionável, digite novamente: ");
                    scanf("%d", &choiceFloor);
                }
                currentFloor = manageElevator(choiceFloor, currentFloor);
                
                break;
                
            //Case 2: Checar andar atual    
            case 2:
                checkCurrentFloor(currentFloor);
                break;
                
            //Case 3: Sair do programa    
            case 3:
                exit(0);
                break;
            
            //Default: Chamado quando um número não relacionado á uma escolha é digitado
            default:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                drawFloors(currentFloor);
                printf("\n %d não é uma escolha selecionável.\n", inputChoice);
                sleep(1);
        }
    }
    return 0;
} 

void drawFloors(int currentFloor){
    int FloorsQuantity = 17;
    
    for(int j = FloorsQuantity; j > 0; j--){
        if(j == currentFloor){
            printf("|x| Andar %d - Você está aqui.\n", currentFloor);
        } else {
            printf("| | Andar %d\n", j);
        }
    }
}

int elevatorRun(int floorBetween, int currentFloor, int direction){
    for(int i = 0; i <= floorBetween; i ++){
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        
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
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    drawFloors(currentFloor);
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
