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
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

string n;
int k;
ll dp[110][4][2];

void solve(){
  cin >> n;
  cin >> k;
  int m=n.length();
  dp[0][0][0]=1;
  rep(i,m){
    ll s=n[i]-'0';
    //cout << s << endl;
    rep(l,k){
      dp[i+1][l+1][1]+=max((ll)0,(s-(ll)1))*dp[i][l][0];
      dp[i+1][l+1][1]+=(ll)9*dp[i][l][1];
      if(s!=0) dp[i+1][l+1][0]+=(ll)dp[i][l][0];
    }
    rep(l,k+1){
      if(s==0) {
        dp[i+1][l][0]+=dp[i][l][0];
        dp[i+1][l][1]+=dp[i][l][1];
      }
      else{
        //cout << i << " " << k << " " << endl;
        dp[i+1][l][1]+=dp[i][l][0]+dp[i][l][1];
        //cout << dp[i+1][l][1] << endl;
      }
    }
  }
  rep(i,m+1){
    rep(l,k+1){
      rep(flag,2){
        //cout << i << " " << l << " " << flag << " " << dp[i][l][flag] << endl;
      }
    }
  }
  cout << dp[m][k][0]+dp[m][k][1] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}