#include <iostream>

using namespace std;

int main (){
    int i;
    bool A;
    A = false;
    char S[6];
    cin >> S;
    for (i=0;i<5;i++){
        if(S[i]=='A'&& S[i+1]=='C'){A = true;}
    }
    if(A){cout << "Yes" << endl;}
    else {cout << "No" << endl;}
    return 0;
}
