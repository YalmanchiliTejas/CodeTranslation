#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
const int INF = numeric_limits<int>::max()/2;
const int MOD = 1e9+7;

// a^b
ll mypow(ll a, ll b) {
    if (b == 0) return 1;
    ll tmp = mypow(a, b / 2);
    if (b % 2) return (((tmp*tmp) % MOD)*a) % MOD;
    else return (tmp*tmp) % MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    // dp[i][j] := i 人以下のグループのみで j 人使う
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    dp[0][0]=1;
    vector<ll> fact(n+1), inv(n+1);
    fact[0]=1;
    inv[0] =1;
    for(ll i=1;i<=n;i++){
        fact[i]=fact[i-1]*i;
        fact[i] %= MOD;
        inv[i] = mypow(fact[i],MOD-2);
    }
    vector<vector<ll>> p(n+1,vector<ll>(n+1));
    for(ll i=1;i<=n;i++){
        p[i][1]=i;
        for(ll j=2;j<=i;j++){
            p[i][j] = p[i][j-1] * (i-j+1);
            p[i][j] %= MOD;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
            if(i<a || b<i) continue;
            for(int k=c;k<=d;k++){
                if(j-i*k<0) break;
                ll tmp = dp[i-1][j-i*k];
                tmp *= p[n-j+i*k][i*k]; tmp %= MOD;
                tmp *= inv[k]; tmp %= MOD;
                tmp *= mypow(mypow(fact[i],k),MOD-2); tmp %= MOD;
                dp[i][j] += tmp; dp[i][j] %= MOD;
            }
        }
    }
    cout<<dp[b][n]<<endl;
    return 0;
}