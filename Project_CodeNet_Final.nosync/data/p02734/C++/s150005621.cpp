/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
ll dp[3010][3010][3] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,S;
    cin >> N >> S;
    ll A[3010];
    rep(i,0,N) cin >> A[i];
    ll ans = 0;
    dp[0][0][0] = 1;
    rep(i,0,N){
        rep(j,0,S+1){
            if(j - A[i] >= 0){
               (dp[i+1][j][1] += dp[i][j - A[i]][0]) %= MOD;
               (dp[i+1][j][2] += dp[i][j - A[i]][0]) %= MOD;
               (dp[i+1][j][1] += dp[i][j - A[i]][1]) %= MOD;
               (dp[i+1][j][2] += dp[i][j - A[i]][1]) %= MOD;
            }
            (dp[i+1][j][0] += dp[i][j][0]) %= MOD;
            (dp[i+1][j][1] += dp[i][j][0]) %= MOD;
            (dp[i+1][j][1] += dp[i][j][1]) %= MOD;
            (dp[i+1][j][2] += dp[i][j][1]) %= MOD;
            (dp[i+1][j][2] += dp[i][j][2]) %= MOD;

        }
    }
    print(dp[N][S][2]);

}