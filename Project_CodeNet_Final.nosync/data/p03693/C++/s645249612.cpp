#include<stdio.h>
#include<iostream>
using namespace std;

int r,g,b;
int main (){
    cin >> r >> g >> b;
    int x = g * 10 + b;
    cout << ( x % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
}
