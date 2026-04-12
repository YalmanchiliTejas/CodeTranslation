#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
    ll N,K;
    cin >> N;
    string S;
    cin >> S >> K;
    K--;
    for(ll i = 0; i < N; i++){
        if(S[K] != S[i]) S[i] = '*';
    }
    
    cout << S << "\n";
    return 0;
} 
