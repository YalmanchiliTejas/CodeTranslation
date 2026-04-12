#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define vec_rep(itr,v) for(auto itr = v.begin(); itr != v.end(); ++itr)
const int MOD = 998244353;

int main(void){
    int N,S;
    cin >> N >> S;
    ll dp[N+1][S+1];
    int A[N];
    rep(i,N)cin >> A[i];
    rep(i,N+1)rep(j,S+1)dp[i][j] = 0;
    dp[0][0] = 1;
    ll ans = 0;
    rep(i,N){
        rep(j,S)(dp[i+1][j] += dp[i][j]) %= MOD;
        if(A[i] <= S)dp[i+1][A[i]] += i+1;
        rep1(j,S){
            if(A[i] + j <= S)(dp[i+1][A[i]+j] += dp[i][j]) %= MOD;
            if(A[i] + j == S)(ans += (dp[i][j] * (N-i)) % MOD) %= MOD;
        }
        if(A[i] == S)ans+=(i+1)*(N-i);
    }
    cout << ans << endl;
    return 0;
}