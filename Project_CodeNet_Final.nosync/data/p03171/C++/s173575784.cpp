#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

ll dp[3010][3010];
vector<ll>a;
ll n;

ll rec(ll i,ll j){
    if(dp[i][j]!=0)return dp[i][j];
    if(i==j){
        dp[i][i]=0;
        return 0;
    }
    ll len = j-i;
    if((n-len)%2==0){
        dp[i][j]=rec(i+1,j)+a[i];
        chmax(dp[i][j],rec(i,j-1)+a[j-1]);
        if(j<n)chmax(dp[i][j],rec(i,j-1)+a[j-1]);
    }
    else{
        dp[i][j]=rec(i+1,j)-a[i];
        chmin(dp[i][j],rec(i,j-1)-a[j-1]);
        if(j<n)chmin(dp[i][j],rec(i,j-1)-a[j-1]);
    }
    return dp[i][j];
}

int main(){
    cin >> n;
    a.resize(n);
    rep(i,n)cin>>a[i];
    rep(i,3010)rep(j,3010)dp[i][j]=0;
    cout << rec(0,n) << endl;

    return 0;
}