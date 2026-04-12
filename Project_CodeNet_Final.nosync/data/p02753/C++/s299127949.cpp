#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;

    bool flag = false;
    for(int i = 0; i+1 < S.size(); i++){
        if(S[i] != S[i+1]){
            flag = true;
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}