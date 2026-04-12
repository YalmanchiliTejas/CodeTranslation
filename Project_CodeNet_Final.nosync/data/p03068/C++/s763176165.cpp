#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K; string S;
    cin >> N >> S >> K;
    rep(i, S.length()){
        if(S[i] != S[K-1]) S[i] = '*';
    }
    cout << S << endl;
    return 0;
}