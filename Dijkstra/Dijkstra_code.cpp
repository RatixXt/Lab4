/**
\file Dijkstra_code.cpp 

@author Щербаков Алексей ИУ8-23
@brief Реализация алгоритма Дейкстры

*/

#include <stdlib.h>
#include <conio.h>
#include <iostream>

const int N = 6; 
using namespace std;

int main() {

    int predok[N], nach = 0, D[N];
    bool flag[N];
   
    int A[N][N] = {				
        {0, 3, 11, 14, 22, 22},
        {3, 0, 7, 22, 12, 15},
        {11, 7, 0, 2, 22, 11},
        {14, 22, 2, 0, 9, 22},
        {22, 12, 22, 9, 0, 6},
        {22, 15, 11, 22, 6, 0}
    };

    for (int i = 0; i < N; i++) {
        predok[i] = nach;
        flag[i] = false;
        D[i] = A[nach][i];
    }

   
    flag[nach] = true;
    predok[nach] = 0;
    for (int i = 0; i < N - 1; i++) {
        int k = 0;
        int minras = 22;
        
        for (int j = 0; j < N; j++) {
            if (!flag[j] && minras > D[j]) {
                minras = D[j];
                k = j;
            }
        }
       
        flag[k] = true;
        for (int j = 0; j < N; j++) {
            
            if (!flag[j] && D[j] > D[k] + A[k][j]) {
                D[j] = D[k] + A[k][j];
                predok[j] = k;
            }
        }
    }

    cout<<"Distances:"<<endl;
    for (int i = 0; i < N; i++) {
        printf("From %d to %d: %d\n", nach, i, D[i]);
    }

    getch();
    return 0;
}
