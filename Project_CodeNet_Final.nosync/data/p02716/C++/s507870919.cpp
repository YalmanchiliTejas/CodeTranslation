#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll n;cin >> n;
    vl a(n);rep(i,n)cin >> a[i];
    if(n%2==0){
        vvl dp(n,vl(2,-INF));
        dp[0][0]=a[0];dp[1][1]=a[1];
        rep(i,n-2){
            if(i!=n-3)chmax(dp[i+3][1],dp[i][0]+a[i+3]);
            chmax(dp[i+2][1],dp[i][1]+a[i+2]);
            chmax(dp[i+2][0],dp[i][0]+a[i+2]);
        }
        cout << max(dp[n-1][1],dp[n-2][0]);
    }
    else{
        vvl dp(n,vl(3,-INF));
        dp[0][0]=a[0];dp[1][1]=a[1];dp[2][2]=a[2];
        rep(i,n-2){
            if(i<n-4)chmax(dp[i+4][2],dp[i][0]+a[i+4]);
            if(i!=n-3)chmax(dp[i+3][2],dp[i][1]+a[i+3]);
            if(i!=n-3)chmax(dp[i+3][1],dp[i][0]+a[i+3]);
            chmax(dp[i+2][2],dp[i][2]+a[i+2]);
            chmax(dp[i+2][1],dp[i][1]+a[i+2]);
            chmax(dp[i+2][0],dp[i][0]+a[i+2]);
        }
        cout << max(max(dp[n-1][2],dp[n-2][1]),dp[n-3][0]) <<endl;
    }
}   