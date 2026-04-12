#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <math.h>
#include <string>
#include <iomanip>
#include <locale>
#include <list>
#include <bitset>
#include <tuple>
using namespace std;
#define FORN(i,m,n) for(int i=(m); i<int(n); i++)
#define PRINTVEC(v) FORN(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define PRINTMAT(m) FORN(j,0,m.size()) {PRINTVEC(m[j]);}
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  const int ms = 2e5+5;
  int n; cin>>n;
  ll dp[ms][2], v[ms], ans;
  FORN(i,0,n) cin>>v[i];
  if(n & 1){
    dp[0][1] = v[0];
    dp[1][0] = v[1];
    dp[2][0] = v[2];
    dp[2][1] = v[0] + v[2];
    FORN(i,3,n){
      if(i & 1) dp[i][0] = max(dp[i-2][0], dp[i-3][1]) + v[i];
      else{
	dp[i][0] = max(dp[i-2][0], max(dp[i-3][0], dp[i-4][1])) + v[i];
	dp[i][1] = dp[i-2][1] + v[i];
      }
    }
    ans = max(dp[n-1][0], max(dp[n-2][0], dp[n-3][1]));
  }
  else{
    dp[0][0] = v[0];
    dp[1][0] = v[1];
    FORN(i,0,n){
      if(i & 1) dp[i][0] = max(dp[i-2][0], dp[i-3][0]) + v[i];
      else dp[i][0] = dp[i-2][0] + v[i];
    }
    ans = max(dp[n-1][0], dp[n-2][0]);
  }
  cout<<ans<<endl;
}