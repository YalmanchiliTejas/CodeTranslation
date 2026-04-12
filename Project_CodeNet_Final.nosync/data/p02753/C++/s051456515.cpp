#include <iostream>
#include <string>
using namespace std;
int main(void){
    string S;
    cin >> S;
    if(S[0] != S[1] || S[1] != S[2] || S[0] != S[2]){
        cout << "Yes" << endl; 
    }else{
        cout << "No" << endl;
    }
}