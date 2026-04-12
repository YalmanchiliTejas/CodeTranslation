#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int c=0;
    for (int i = 0; i < S.length()-1; ++i) {
        if(S.at(i) != S.at(i+1)){
            c++;
        }
    }
    if(c > 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}