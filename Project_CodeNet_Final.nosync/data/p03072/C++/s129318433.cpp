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
  int h[n];
  REP(i,n) cin >> h[i];
  int max_h = h[0];
  int ans = 1;
  for(int i = 1; i <= n-1; i++){
    if(h[i]>=max_h){
      ans++;
    }
    max_h = max(max_h,h[i]);
  }
  cout << ans << endl;
  return 0;
}
