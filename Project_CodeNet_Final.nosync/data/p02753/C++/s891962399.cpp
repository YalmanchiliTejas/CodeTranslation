#include<iostream>
#include<string.h>

using namespace std;
int main(){
    char S[4];
    cin >> S;
    if(!strncmp(S,"AAA",4)){
        cout << "No" <<endl;
    }
    else{
        if(!strncmp(S,"BBB",4)){
        cout << "No" << endl;
        }
        else{
        cout << "Yes" << endl;
        }
    }
}