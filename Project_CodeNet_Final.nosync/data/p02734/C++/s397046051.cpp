#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n,s;
  cin >> n >> s;
  ll p=998244353;
  ll dp[n+1][s+1];
  rep(i,n+1)rep(j,s+1)dp[i][j]=0;
  int a[n];
  rep(i,n)cin >> a[i];
  rep(i,n){
    rep(j,s+1){
      if(a[i]+j<=s)dp[i+1][a[i]+j]=(dp[i][j]+dp[i+1][a[i]+j])%p;
      dp[i+1][j]=(dp[i][j]+dp[i+1][j])%p;
    }
    if(a[i]<=s)dp[i+1][a[i]]=(dp[i+1][a[i]]+1)%p;
    dp[i+1][0]=(1+dp[i+1][0])%p;
  }
  ll ans=0;
  rep(i,n){
    ans=(ans+dp[i+1][s])%p;
  }
  //rep(i,n+1)rep(j,s+1)cout << dp[i][j] << endl;
  cout << ans << endl;
}
