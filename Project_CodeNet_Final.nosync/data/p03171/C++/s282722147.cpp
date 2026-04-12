#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
 
using namespace std;
 
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
 
const ll mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    rep(i,n+1) dp[i][i]=0;
    for(ll w=1;w<=n;w++){
        for(ll l=0;l+w<=n;l++){
            ll r=l+w;
            if(w%2==n%2){
                dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r-1]);
            }
            else{
                dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r-1]);
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
} 