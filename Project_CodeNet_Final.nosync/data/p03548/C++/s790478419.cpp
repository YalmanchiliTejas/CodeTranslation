//ISU
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main(){
    long long X,Y,Z;
    cin >> X >> Y >> Z;
    long long YZ = Y+Z;
    X -= Y+2*Z;
    long long ans = X/YZ + 1;
    cout << ans << endl;
    return 0;
}