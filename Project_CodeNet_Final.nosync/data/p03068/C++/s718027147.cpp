#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod=1e9+7;

int main(){
    int N, K;
    string S;
    cin >> N >> S >> K;
    for(int i=0; i<N; i++){
        if(S[i]!=S[K-1]){
            S[i] = '*';
        }
    }
    cout << S;
}