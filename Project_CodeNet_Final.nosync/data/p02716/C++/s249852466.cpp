#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    ll dp[n+1][3];
    rep(i,n+1)rep(j,3) dp[i][j]=-LINF;
    dp[0][0]=0;
    rep(i,n){
        if(i%2){
            chmax(dp[i+1][0],dp[i][0]);
            chmax(dp[i+1][1],dp[i][1]+a[i]);
            chmax(dp[i+1][2],dp[i][2]);

            if(i>0) chmax(dp[i+1][1],dp[i-1][0]+a[i]);
            
        }else{
            chmax(dp[i+1][0],dp[i][0]+a[i]);
            chmax(dp[i+1][1],dp[i][1]);
            chmax(dp[i+1][2],dp[i][2]+a[i]);
            
            if(i>1){
                chmax(dp[i+1][2],dp[i-2][0]+a[i]);
                chmax(dp[i+1][2],dp[i-1][1]+a[i]);
            }
        }
    }
    if(n%2){
        cout<<max({dp[n-1][0],dp[n][1],dp[n][2]})<<endl;
    }else{
        cout<<max({dp[n][0],dp[n][1]})<<endl;
    }
    return 0;
}
