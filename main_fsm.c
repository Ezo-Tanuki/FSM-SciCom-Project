#include <stdio.h>

void calcState(int* nextState, int* currentState, int* input);
void calcOutput(int* output, int* currentState);
void printOutput(int* output);

int main(void){
    int input2Bit[2];
    int currentState[] = {0, 0};
    int nextState[2];
    int output[2];

    while(1){
        scanf("%d %d", input2Bit, input2Bit+1);
        calcState(nextState, currentState, input2Bit);
        currentState[0] = nextState[0];
        currentState[1] = nextState[1];
        calcOutput(output, currentState);
        printOutput(output);
    }

    return 0;
}


void calcState(int* nextState, int* currentState, int* input){
    nextState[0] = currentState[0] & !currentState[1] | currentState[0] & input[1] | currentState[1] & input[0] | !currentState[0] & input[0];
    nextState[1] = !currentState[0] & currentState[1] | input[1] | currentState[1] & input[0];
}

void calcOutput(int* output, int* currentState){
    output[0] = !currentState[0];
    output[1] = !currentState[1];
}

void printOutput(int* output){
    if(!output[0] & !output[1]){
        printf("Ready to print!\n");
        return;
    }

    if(output[0]) printf("Please fill up the ink!\n");
    if(output[1]) printf("Please fill up the paper!\n");
}
