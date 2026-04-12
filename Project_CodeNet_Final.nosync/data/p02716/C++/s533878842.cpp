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

const ll INF=-1e15;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll even_sum=0;
    ll odd_sum=0;
    rep(i,n){
        cin >> a[i];
        if(i%2==0){
            even_sum+=a[i];
        }
        else{
            odd_sum+=a[i];
        }
    }
    ll k=n/2; //選べる数字の数
    ll ex=(n%2)+2;
    
    vector<vector<ll>> dp(k+1,vector<ll>(ex,INF));
    rep(i,ex){
        dp[1][i]=a[i];
    }
    for(ll i=2;i<=k;i++){
        rep(j,ex){
            ll M=INF;
            rep(m,ex){
                if(j>=m){
                    if(dp[i-1][m]==INF) continue;
                    M=max(M,dp[i-1][m]);
                }
            }
            
            dp[i][j]=M+a[2*i+j-2];
        }
    }
    ll ans=INF;
    rep(i,ex){
        ans=max(dp[k][i],ans);
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
} 
