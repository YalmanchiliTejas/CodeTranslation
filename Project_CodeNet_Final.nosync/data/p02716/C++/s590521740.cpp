#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int n;ll a[200010];
ll dp[200010][4][2];

void solve(){
  cin >> n;
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n+1){
    rep(j,4){
      rep(flag,2){
        dp[i][j][flag]=-INF;
      }
    }
  }
  dp[0][0][0]=0;
  rep(i,n){
    rep(j,3){
      dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][0]+a[i]);
      if(j<2)dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][0]);
      dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][1]);
    }
  }
  // rep(i,n+1){
  //   rep(j,3){
  //     rep(flag,2){
  //       cout << i << " " << j << " " << flag << " " << dp[i][j][flag] << endl;
  //     }
  //   }
  // }
  if(n%2) cout << max(dp[n][1][0],dp[n][2][1]) << endl;
  else cout << max(dp[n][0][0],dp[n][1][1]) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}
