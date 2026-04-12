#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>
#include<map>
using namespace std;

int main(){
    int X,Y,Z;
    cin >> X >> Y >> Z ;
    int cor = X/(Y+Z);
    if(X%(Y+Z) < Z)cor -=1;
    cout << cor << endl;

}