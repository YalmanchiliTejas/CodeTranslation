#include <bits/stdc++.h>

#define llint long long int

using namespace std;

int main(){
    string S;

    cin >> S;

    for(int i = 1; i < S.length(); i ++){
        if(S[0] != S[i]){
            cout << "Yes" << endl;

            return 0;
        }
    }
    cout << "No" << endl;
}