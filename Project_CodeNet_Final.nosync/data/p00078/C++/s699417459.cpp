#include<iostream>
#include<cstdio>
#define N 16
using namespace std;

int n;
int str[N][N];
bool checkstr[N][N];

void reset();
void disp();
void loop(int i, int j, int num, int c);

int main(){
    while(cin >>n){
        if(n == 0) break;
        reset();
        str[n / 2 + 1][n / 2] = 1;
        checkstr[n / 2 + 1][n / 2] = true;
        loop(n / 2 + 2, n / 2 + 1, 2, 1);
        disp();
    }
    return 0;
}

void reset(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            checkstr[i][j] = false;
        }
    }
}
void disp(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%4d", str[i][j]);
        }
        cout <<endl;
    }
}

void loop(int i, int j, int num, int c){
    c++;
    if(c <= (n * n)){
        if(i >= n) i = 0;
        if(j >= n) j = 0;
        while(checkstr[i][j] == true){
            i++;
            j--;
            if(i >= n) i = 0;
            if(j < 0) j = n - 1;
        }
        str[i][j] = num;
        checkstr[i][j] = true;
        i++;
        j++;
        num++;
        loop(i, j, num, c);
    }
}