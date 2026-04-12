#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<iosfwd>
#include<sstream>
#define N 100
using namespace std;
int main(){
    int n,k;
    string s;
    cin >> n >> s >> k;
    const char* x= s.c_str();
    char t= x[k-1];
    for(int i=0; i<strlen(x); i++){
        if(x[i]==t) cout << t;
        else cout << "*";
    }
    cout << endl;
}
