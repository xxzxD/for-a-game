// generate a random position and emulate to find results less than 15 times

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXTIME 15

int changeState(int state);
void changeRC(int a[][4], int m, int n);
int checkArray(int a[][4]);
void initializeArray(int a[][4]);
void printResult(int result[][2], int num);

int main(int argc, const char * argv[]) {
    int a[4][4];
    int result[21][2] = {0};
    initializeArray(a);
    int x, y;
    int i = 1000;
    srand((unsigned)time(NULL));
    
    while(i >= MAXTIME){
        i = 0; // use to count how many times in a success finding
        initializeArray(a); // initialize everytime
        while(checkArray(a) != 1){ // if not found then loop
            x = rand() % 4;  // random number
            y = rand() % 4;
            changeRC(a, x, y); // choose a random position
            
            result[i][0] = x + 1; // add 1 to better show results
            result[i][1] = y + 1;
            
            i++; // add 1 time
            
            // filtrate results larger than 15 times
            if(i >= MAXTIME)
                break;
        }
    }
    printf("%d times\n",i);
    printResult(result, i);
    return 0;
}

// input array to initialize
void initializeArray(int a[][4]){
    a[0][0]=0;
    a[0][1]=0;
    a[0][2]=0;
    a[0][3]=0;
    a[1][0]=0;
    a[1][1]=1;
    a[1][2]=0;
    a[1][3]=1;
    a[2][0]=1;
    a[2][1]=0;
    a[2][2]=0;
    a[2][3]=0;
    a[3][0]=1;
    a[3][1]=0;
    a[3][2]=0;
    a[3][3]=0;
}

// change state, 0 means - , 1 means |
int changeState(int state){
    return !state;
}

// change the row and column state of the specific position (m,n)
void changeRC(int a[][4], int m, int n){
    int i = 0;
    
    // change row
    for(i = 0; i < 4; i++){
        a[m][i] = changeState(a[m][i]);
    }
    // change column
    for(i = 0; i < 4; i++){
        a[i][n] = changeState(a[i][n]);
    }
    // change 2 times, so need change 1 more time
    a[m][n] = changeState(a[m][n]);
}

// to check if all items not equals 0, which means all is |
int checkArray(int a[][4]){
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(a[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

// print result
void printResult(int result[][2], int num){
    int i;
    for(i = 0; i < num; i++){
            printf("%d %d\n", result[i][0], result[i][1]);
        }
    printf("\n");
}
