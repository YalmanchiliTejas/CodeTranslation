#include<iostream>

using namespace std;

int main(){

    string S;
    cin >> S;
    char c = S[0];
    int count = 0;
    for (int i = 1; i < S.size(); i++){
        if(c != S[i]){
            count++;
        }
        c = S[i];
    }
    if(count == 0){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}