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

ll n,s,a[3001],dp[3001][6100][3];

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n>>s;
    rep(i,n) cin>>a[i];

    rep(i,n){
        dp[i][0][0]=1;
        for(int j=3000;j>=0;j--){
            //左端指定
            dp[i+1][j+a[i]][1]+=dp[i][j][0];    dp[i+1][j+a[i]][1]%=mod;
            dp[i+1][j][1]+=dp[i][j][0];         dp[i+1][j][1]%=mod;
            //区間伸ばし
            dp[i+1][j+a[i]][1]+=dp[i][j][1];    dp[i+1][j+a[i]][1]%=mod;
            dp[i+1][j][1]+=dp[i][j][1];         dp[i+1][j][1]%=mod;
            //区間閉じ
            dp[i+1][j+a[i]][2]+=dp[i][j][0];    dp[i+1][j+a[i]][2]%=mod;
            dp[i+1][j][2]+=dp[i][j][0];         dp[i+1][j][2]%=mod;
            dp[i+1][j+a[i]][2]+=dp[i][j][1];    dp[i+1][j+a[i]][2]%=mod;
            dp[i+1][j][2]+=dp[i][j][1];         dp[i+1][j][2]%=mod;
            dp[i+1][j][2]+=dp[i][j][2];         dp[i+1][j][2]%=mod;

            //modint導入しておけばよかったと反省しています
        }
    }
    cout<<dp[n][s][2]<<endl;
    return 0;
}
