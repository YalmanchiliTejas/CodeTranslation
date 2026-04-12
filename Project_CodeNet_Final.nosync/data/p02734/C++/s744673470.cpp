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
ll dp[3010][3010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,S;
    cin >> N >> S;
    ll A[3010];
    rep(i,0,N) cin >> A[i];
    // dp[0][0] = 1;
    ll ans = 0;
    rep(i,0,N){
        rep(j,0,S+1){
            (dp[i+1][j] += dp[i][j]) %= MOD;
        }
        if(S - A[i] >= 0) ans += dp[i+1][S - A[i]] * (N-i);
        ans %= MOD;
        (dp[i+1][A[i]] += i+1) %= MOD;
        rep(j,1,S+1){
            if(j - A[i] >= 0) (dp[i+1][j] += dp[i][j - A[i]]) %= MOD;
        }
        if(A[i] == S){
            ans += (i+1) * (N-i);
            ans %= MOD;
        }
    }

    print(ans);
    

}
