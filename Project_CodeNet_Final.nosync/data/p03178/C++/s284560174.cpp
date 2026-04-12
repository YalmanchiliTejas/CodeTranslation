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

ll dp[10010][2][105];

int main()
{
    string k;
    cin >> k;
    ll d;
    cin >> d;
    ll n=k.length();
    dp[0][0][0]=1;
    for(ll i=1;i<=n;i++){
        ll x=(ll)(k[i-1]-'0');
        for(ll j=0;j<=9;j++){
            for(ll p=0;p<d;p++){
                if(j==x){
                    dp[i][0][(p+j)%d]+=dp[i-1][0][p];
                    dp[i][0][(p+j)%d]%=mod;
                }
                if(j<x){
                    dp[i][1][(p+j)%d]+=(dp[i-1][1][p]+dp[i-1][0][p])%mod;
                    dp[i][1][(p+j)%d]%=mod;
                }
                else{
                    dp[i][1][(p+j)%d]+=dp[i-1][1][p];
                    dp[i][1][(p+j)%d]%=mod;
                }
            }
        }
    }
    ll ans=(dp[n][0][0]+dp[n][1][0]+mod-1)%mod;
    cout <<  ans << endl;
    return 0;
} 