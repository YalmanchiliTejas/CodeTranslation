#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <set>
#include <string.h>

using namespace std;

typedef long long ll;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REP3(i,st,en) for(ll (i)=(st);(i)<(en);(i)++)

using P = pair<ll, ll>;
const int MOD = 1e9+7;
const ll INF = 1e+14;
const double PI = 3.14159265349;



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string N;
  ll K;
  cin >> N >> K;

  ll D = N.length();

  vector<vector<ll>> dp0(D,vector<ll>(4,0));  // lower than N
  vector<vector<ll>> dp1(D,vector<ll>(4,0));  // not decided to lower than N
  dp0[0][0] = 1;
  dp1[0][0] = 0;
  dp0[0][1] = N[0]-'0'-1;
  dp1[0][1] = 1;

  // devide from higer bit
  REP3(i,1,D){
    dp0[i][0] = 1;;
    ll d = N[i]-'0';
    // K=1 
    dp0[i][1] = dp0[i-1][0]*9 + dp1[i-1][0]*max(0ll,d-1); // 1~9
    dp0[i][1] += (d>0) ? dp0[i-1][1] + dp1[i-1][1] : dp0[i-1][1]; // 0
    dp1[i][1] = (d>0) ? dp1[i-1][0] : dp1[i-1][1];
    // K=2
    dp0[i][2] = dp0[i-1][1]*9 + dp1[i-1][1]*max(0ll,d-1); // 1~9
    dp0[i][2] += (d>0) ? dp0[i-1][2] + dp1[i-1][2] : dp0[i-1][2]; // 0
    dp1[i][2] = (d>0) ? dp1[i-1][1] : dp1[i-1][2];
    // K=3
    dp0[i][3] = dp0[i-1][2]*9 + dp1[i-1][2]*max(0ll,d-1); // 1~9
    dp0[i][3] += (d>0) ? dp0[i-1][3] + dp1[i-1][3] : dp0[i-1][3]; // 0
    dp1[i][3] = (d>0) ? dp1[i-1][2] : dp1[i-1][3];
  }

  ll ans = dp0[D-1][K] + dp1[D-1][K];
  cout << ans << "\n";
  return 0;
}
