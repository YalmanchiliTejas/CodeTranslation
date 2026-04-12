#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

const ll p = 1000000007;

int main(){
  string k;
  cin >> k;
  ll d;
  cin >> d;
  int k_sep[k.length()];
  REP(i,k.length()) k_sep[i] = k[i]-'0';
  ll n = k.length();//kの桁数
  ll dp[n][d];
  fill(dp[0],dp[n],0);
  REP(j,10){
    dp[0][j%d]++;
  }
  REP(i,n-1) REP(j,d) REP(l,10){
    dp[i+1][(j+l)%d] += dp[i][j];
    dp[i+1][(j+l)%d] %= p;
  }
  ll ans = 0;
  ll sum = 0;
  REP(i,n-1){
    REP(j,k_sep[i]){
      ans += dp[n-2-i][(2*d-sum-j)%d];
      ans %= p;
    }
    sum += k_sep[i];
    sum %= d;
  }
  REP(j,k_sep[n-1]+1){
    if((sum+j)%d==0) ans++;
  }
  cout << (ans+p-1)%p << endl;
  return 0;
}
