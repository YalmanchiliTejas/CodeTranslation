#include<bits/stdc++.h>
using namespace std;

// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

ll dp[3010][3010];
ll a[3010];

ll rec(int l, int r, int player){// player? taro : jiro
    if(dp[l][r]!=-1) return dp[l][r];
    if(r==l+1){
        if(player) return dp[l][r] = a[l];
        else return dp[l][r] = -a[l];
    }
    ll res = 0;
    if(player){
        res = max( rec(l,r-1,!player) + a[r-1] , rec(l+1,r,!player) + a[l] );
    }
    else{
        res = min( rec(l,r-1,!player) - a[r-1] , rec(l+1,r,!player) - a[l] );
    }
    return dp[l][r] = res;
}

int main(){
    int N; cin>>N;
    rep(i,N)cin>>a[i];
    rep(i,3010)rep(j,3010) dp[i][j] = -1;
    cout<<rec(0,N,1)<<endl;
}