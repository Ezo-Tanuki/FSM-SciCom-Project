#include <stdio.h>
#include <stdlib.h>

void calcState(int* nextState, int* currentState, int* input);
void calcOutput(int* output, int* currentState);
void printOutput(int* output);
void printCurrentState(int* currentState);

int main(void){
    system("clear");

    int input2Bit[2];
    int currentState[] = {0, 0};
    int output[2] = {1, 1};
    int nextState[2];
    
    printOutput(output);
    printCurrentState(currentState);

    while(1){    
        scanf("%d %d", input2Bit, input2Bit+1);

        system("clear");
        calcState(nextState, currentState, input2Bit);
        currentState[0] = nextState[0];
        currentState[1] = nextState[1];
        calcOutput(output, currentState);
        printf("\n");
        printOutput(output);
        printCurrentState(currentState);
    }

    return 0;
}


void calcState(int* nextState, int* currentState, int* input){
    nextState[0] = currentState[0] & !currentState[1] | currentState[0] & input[1] | input[0];
    nextState[1] = !currentState[0] & currentState[1] | input[1] | currentState[1] & input[0];
}

void calcOutput(int* output, int* currentState){
    output[0] = !currentState[0];
    output[1] = !currentState[1];
}

void printOutput(int* output){
    if(!output[0] & !output[1]){
        printf(
        "\n"
        ",----,------------------------------,------.\n"
        "| \033[0;32m##\033[0m |                              |    - |\n"
        "| \033[0;32m##\033[0m |                              |    - |\n"
        "|    |------------------------------|    - |\n"
        "|    ||............................||      |\n"
        "|    ||,-                        -.||      |\n"
        "|    ||___                      ___||    \033[0;32m##\033[0m|\n"
        "|    ||---`--------------------'---||      |\n"
        "`--mb'|_|______________________==__|`------'\n");
        printf("Ready to print!\n");
    }

    else if(output[0] & !output[1]){
        printf(
        "\n"
        ",----,------------------------------,------.\n"
        "| \033[0;32m##\033[0m |                              |    - |\n"
        "| \033[0;32m##\033[0m |                              |    - |\n"
        "|    |------------------------------|    - |\n"
        "|    ||............................||      |\n"
        "|    ||,-                        -.||      |\n"
        "|    ||___                      ___||    \033[0;31m##\033[0m|  \033[0;31mInk is empty!\033[0m\n"
        "|    ||---`--------------------'---||      |\n"
        "`--mb'|_|______________________==__|`------'\n");
        printf("Please fill up the ink!\n");
    } 
    else if(!output[0] & output[1]){
        printf(
        "\n"
        "   \033[0;31mPaper is empty!\033[0m\n"
        ",----,------------------------------,------.\n"
        "| \033[0;31m##\033[0m |                              |    - |\n"
        "| \033[0;31m##\033[0m |                              |    - |\n"
        "|    |------------------------------|    - |\n"
        "|    ||............................||      |\n"
        "|    ||,-                        -.||      |\n"
        "|    ||___                      ___||    \033[0;32m##\033[0m|\n"
        "|    ||---`--------------------'---||      |\n"
        "`--mb'|_|______________________==__|`------'\n");
        printf("Please fill up the paper!\n");
    } 

    else{
        printf(
        "   \033[0;31mPaper is empty!\033[0m\n"
        ",----,------------------------------,------.\n"
        "| \033[0;31m##\033[0m |                              |    - |\n"
        "| \033[0;31m##\033[0m |                              |    - |\n"
        "|    |------------------------------|    - |\n"
        "|    ||............................||      |\n"
        "|    ||,-                        -.||      |\n"
        "|    ||___                      ___||    \033[31m##\033[0m|  \033[0;31mInk is empty!\033[0m\n"
        "|    ||---`--------------------'---||      |\n"
        "`--mb'|_|______________________==__|`------'\n");
        printf("Please fill up the ink!\n");
        printf("Please fill up the paper!\n");
    }
}

void printCurrentState(int* currentState){
    printf("current state: %d%d\n", currentState[0], currentState[1]);
}
/*
  ,----,------------------------------,------.
  | ## |                              |    - |
  | ## |                              |    - |
  |    |------------------------------|    - |
  |    ||............................||      |
  |    ||,-                        -.||      |
  |    ||___                      ___||    ##|
  |    ||---`--------------------'---||      |
  `--mb'|_|______________________==__|`------'
  Artist: Martin Brunzel
  Source: https://ascii.co.uk/art/printer
*/