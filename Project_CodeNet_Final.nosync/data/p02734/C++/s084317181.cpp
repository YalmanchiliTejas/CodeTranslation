#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 998244353
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N,S; cin>>N>>S;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];

    vector<vector<ll>> dp(N+1,vector<ll>(S+1,0));
    rep(r,N){
        rep(s,S+1){
            dp[r+1][s] = dp[r][s];
            if(s>=A[r])dp[r+1][s] += dp[r][s-A[r]];
            if(s==0||s==A[r]) dp[r+1][s]++;
            dp[r+1][s] %= MOD;
        }
    }
    ll res = 0;
    rep1(r,N){
        res += dp[r][S];
        res %= MOD;
    }
    cout<<res<<endl;
}
