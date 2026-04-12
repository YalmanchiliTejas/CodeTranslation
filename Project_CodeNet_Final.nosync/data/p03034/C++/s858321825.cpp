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

int main(){
  int n; cin >> n;
  ll s[n];
  REP(i,n) cin >> s[i];
  ll ans = 0;
  for(int c = 1; c<n-1; c++){
    ll dp = 0;
    for(int k = 1; k*c<n-1-c;k++){
      if((n-1-k*c)%c==0&&(n-1-k*c)/c<=k) break;
      dp += s[k*c]+s[n-1-k*c];
      ans = max(ans,dp);
    }
  }
  cout << ans << endl;
  return 0;
}
