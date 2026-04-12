#include<stdio.h>
#include<stddef.h>
#include<iostream>
using namespace std;

int main(){
    string S;
    cin >> S;
    if(S[0]==S[1] && S[1]==S[2]){
        cout << "No";
    } else {
        cout << "Yes";
    }
}

