#include<stdio.h>
#include<iostream>
using namespace std;

int X,Y,Z;
int main (){
    cin >> X >> Y >> Z;
    int ans = 0;
    ans = (X - Z) / ( Y + Z);
    cout << ans << endl;
    return 0;
}
