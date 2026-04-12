#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

int main(){
    string S;
    cin>>S;
    if (S[0]==S[1]&&S[1]==S[2]){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
    return 0;
}