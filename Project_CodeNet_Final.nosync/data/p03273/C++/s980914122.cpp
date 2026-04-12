#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,n) for(int i = (n); i > -1; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h,w;
  cin>>h>>w;
  char a[h][w];
  rep(i,h) {
    rep(j,w) cin>>a[i][j];
  }
  bool fh[h];
  bool fw[w];
  rep(i,h) fh[i] = false;
  rep(i,w) fw[i] = false;
  rep(i,h) {
    bool flag = true;
    rep(j,w) {
      if(a[i][j] == '#') flag = false;
    }
    if(flag) fh[i] = true;
  }
  rep(j,w) {
    bool flag = true;
    rep(i,h) {
      if(a[i][j] == '#') flag = false;
    }
    if(flag) fw[j] = true;
  }
  rep(i,h) {
    if(fh[i]) continue;
    rep(j,w) {
      if(fw[j]) continue;
      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}
