#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <random>
#include <fstream>
#include <time.h>
// #define int long long
#define debug(x) cerr << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,n) for(int i = (n); i > -1; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1000000007;
const ll LINF = 1e18;
const double EPS = 1e-9;


signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  int h[n];
  rep(i,n) cin>>h[i];
  int ans = 0;
  rep(i,n) {
    bool f = false;
    rep(j,i) {
      if(h[j] > h[i]) {
        f = true;
      }
    }
    if(!f) ans++;
  }
  cout << ans << endl;

  return 0;
}
