#include<stdio.h>
#include<iostream>
using namespace std;

int N;
int main (){
    cin >> N;

int x = 800 * N;
int y = N / 15 * 200;

    cout << x - y << endl;
    return 0;
}
