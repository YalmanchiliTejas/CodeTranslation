#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max()/2;
const int MOD = 1e9+7;

// a^b
ll mypow(ll a, ll b) {
    if (b == 0) return 1;
    ll tmp = mypow(a, b / 2);
    if (b % 2) return (((tmp*tmp) % MOD)*a) % MOD;
    else return (tmp*tmp) % MOD;
}
 
// nCk
ll comb(ll n, ll k) {
    ll res = 1;
    k = min(n - k, k);
    for (ll i = n - k + 1; i <= n; i++) res = (res*i) % MOD;
    for (ll i = 1; i <= k; i++)res = (res*mypow(i, MOD - 2)) % MOD;
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,d,x;
    while(cin>>n>>d>>x, n){
        vector<vector<ll>> dp(2222,vector<ll>(2222,0));
        dp[0][0]=1;
        vector<ll> sum(2222,0);
        d%=MOD;
        for(int i=1;i<=min(d,n);i++){
            sum[0]=dp[i-1][0];
            for(int j=1;j<=n;j++){
                sum[j]=sum[j-1]+dp[i-1][j];
                sum[j] %= MOD;
                //cout<<sum[j]<<endl;
            }
            for(int j=1;j<=n;j++){
                dp[i][j]=sum[j-1];
                dp[i][j]+=MOD;
                if(j-x>=0) dp[i][j]-=sum[j-x];
                dp[i][j]%=MOD;
            }
        }
        ll res=0;
        for(int i=1;i<=min(d,n);i++){
            //cout<<dp[i][n]<<endl;
            res += dp[i][n] * comb(d,i);
            res %= MOD;
        }
        cout<<res<<endl;
    }
}
