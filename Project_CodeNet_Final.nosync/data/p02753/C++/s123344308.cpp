#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long int MOD = 1000000007;
const long long  INF = 1LL << 60;

bool solve(string S){
    for(int i = 0; i < S.size()-1; i++){
        if (S[i] != S[i+1]) return true;
    }
    return false;
}

int main(void){
    string S; cin >> S;
    
    if(solve(S)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
