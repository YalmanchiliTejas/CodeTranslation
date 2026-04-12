#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(void){
    std::string s;
    int ans=0;
    cin >> s;

    for(int i=0;i<5;i++){
        if(s[i]=='A' && s[i+1]=='C'){ans++;}
        else{;}
    }

    if(ans>=1){printf("Yes");}
    else{printf("No");}
}