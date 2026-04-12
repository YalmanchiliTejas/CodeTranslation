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


ll dp[105][4][2];

int main()
{
    string s;
    cin >> s;
    ll n=s.length();
    ll k;
    cin >> k;
    for(ll i=0;i<=n;i++){
        if(i==0){
            dp[0][0][0]=1;
            continue;
        }
        if((s[i-1]-'0')==0){
            for(ll j=0;j<=k;j++){
                if(j-1>=0){
                    dp[i][j][1]+=9*dp[i-1][j-1][1];
                }
                dp[i][j][0]+=dp[i-1][j][0];
                dp[i][j][1]+=dp[i-1][j][1];
            }
        }
        else{
            for(ll j=0;j<=k;j++){
                if(j-1>=0){
                    dp[i][j][0]+=dp[i-1][j-1][0];
                    dp[i][j][1]+=9*dp[i-1][j-1][1];
                    dp[i][j][1]+=((s[i-1]-'0')-1)*dp[i-1][j-1][0];
                }
                dp[i][j][1]+=dp[i-1][j][0]+dp[i-1][j][1];
            }
        }
    }
    cout << dp[n][k][0]+dp[n][k][1] << endl;
    return 0;
} 