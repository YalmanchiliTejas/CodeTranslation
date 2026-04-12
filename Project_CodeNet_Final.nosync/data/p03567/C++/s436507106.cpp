#include<stdio.h>
#include<iostream>
using namespace std;

string S;
int main (){
    cin >> S;
    int flag = 0;
    for(int i=0; i<S.length()-1; i++){
        if ( S[i] == 'A' && S[i+1] == 'C') flag = 1;
    }
    cout << ( flag ? "Yes" : "No" )  << endl;
    return 0;
}
