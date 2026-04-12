#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 50;
ll dp[MAX_N+1]; // dp[i] := レベルiバーガーの枚数

ll rec(ll N, ll X){
    if(N == 0) return 1;

    if(X == 1) return 0;
    else if(X <  (dp[N] + 1) / 2)return rec(N-1, X-1);
    else if(X == (dp[N]+1)/2) return rec(N-1, dp[N-1]) + 1;
    else if(X < dp[N]) return rec(N-1, dp[N-1]) + 1 + rec(N-1, X - (dp[N]+1)/2);
    else return 2 * rec(N-1, dp[N-1]) + 1;
}

int main(){
    ll N, X;cin >> N >> X;
    for(int i = 0; i <= N; i++){
        if(i == 0)dp[i] = 1;
        else dp[i] = 2 * dp[i-1] + 3;
    }
    cout << rec(N, X) << endl;
}