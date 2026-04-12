#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

vector<int> lcs(vector<int> a, vector<int> b) { // O(nm)
  int n = a.size();
  int m = b.size();
  int dp[n+1][m+1];
  int f[n+1][m+1];
  REP(i,n) {
    REP(j,m) {
      if (a[i] == b[j]) {
        dp[i+1][j+1] = dp[i][j] + 1;
        f[i+1][j+1] = 0;
      } else if (dp[i+1][j] > dp[i][j+1]) {
        dp[i+1][j+1] = dp[i+1][j];
        f[i+1][j+1] = 1;
      } else {
        dp[i+1][j+1] = dp[i][j+1];
        f[i+1][j+1] = -1;
      }
    }
  }
  vector<int> res;
  for (int i=n, j=m; i>0&&j>0;) {
    if (f[i][j]>0) --j;
    else if (f[i][j]<0) --i;
    else {--i;--j;res.push_back(a[i]);}
  }
  reverse(ALL(res));
  return res;
}
int dp[300][300];
int f[300][300];

int main() {
  string s;
  while(cin >> s, s != "#END") {
    int ma = 0;
    string ans;
    for (int i=1; i<s.size(); ++i) {
      string a = s.substr(0, i);
      string b = s.substr(i);
      int n = a.size(), m = b.size();
      REP(j,n+1) dp[j][0] = 0;
      REP(j,m+1) dp[0][j] = 0;
      REP(j,n) {
        REP(k,m) {
          if (a[j] == b[k]) {
            dp[j+1][k+1] = dp[j][k] + 1;
            f[j+1][k+1] = 0;
          } else if (dp[j+1][k] > dp[j][k+1]) {
            dp[j+1][k+1] = dp[j+1][k];
            f[j+1][k+1] = 1;
          } else {
            dp[j+1][k+1] = dp[j][k+1];
            f[j+1][k+1] = -1;
          }
        }
      }
      if (dp[n][m] > ma) {
        ma = dp[n][m];
        ans = "";
        for (int j=n, k=m; j>0&&k>0;) {
          if (f[j][k]>0) --k;
          else if (f[j][k]<0) --j;
          else {--j;--k; ans+=string(1,a[j]);}
        }
        reverse(ALL(ans));
      }
    }
    cout << ans << endl;
  }
}