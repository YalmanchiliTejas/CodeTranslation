#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 998244353
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

ll dp[3010][6100],ans;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,s;cin>>n>>s;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    rep(i,n){
        dp[i][0]++;
        for(int j=3000;j>=0;j--){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=mod;
            dp[i+1][j+a[i]]+=dp[i][j];
            dp[i+1][j+a[i]]%=mod;
        }
        ans+=dp[i+1][s]*(n-i)%mod;
        ans%=mod;
        dp[i+1][s]=0;
    }
    cout<<ans<<endl;
    return 0;
}
