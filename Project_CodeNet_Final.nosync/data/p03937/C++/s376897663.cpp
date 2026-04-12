#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ll long long
#define ld double
#define ull unsigned long long
#define PI pair < int, int > 

const int N = 123;
const int M = 123;
const ld Pi = acos(-1);
const ll Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int Sz = 501;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) {
  return 1ll * a * b % mod;
}
int sum(int a, int b) {
  add(a, b);
  return a;
}

int n, m, dp[N][N], cnt[N];
char a[N][N];
queue < pair < int, int > > q;

void solve() { 
  cin >> n >> m;
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= m;j++) {
      cin >> a[i][j];
      dp[i][j] = inf;
      if (a[i][j] == '.') continue;
      int dist = i + j - 1;
      cnt[dist]++;
    }
  }
  for (int i = 1;i <= n + m - 1;i++) {
    //cout << "i = " << i << " cnt = " << cnt[i] << endl;
    if (cnt[i] != 1) {
      cout << "Impossible\n";
      return;
    }
  }
  q.push({1, 1});
  dp[1][1] = 1;
  while(q.size()) {
    int x = q.front().f;
    int y = q.front().s;
    q.pop();
    if (x < n && a[x + 1][y] == '#' && dp[x + 1][y] > dp[x][y] + 1) {
      dp[x + 1][y] = dp[x][y] + 1;
      q.push({x + 1, y});
    }
    if (y < m && a[x][y + 1] == '#' && dp[x][y + 1] > dp[x][y] + 1) {
      dp[x][y + 1] = dp[x][y] + 1;
      q.push({x, y + 1});
    }
  }
  if (dp[n][m] == inf) cout << "Impossible\n";
  else cout << "Possible\n";
}
  
int main() {
  #ifdef wws
   freopen("in", "r", stdin);
   // freopen("in", "w", stdout);
  #endif 
  ios_base::sync_with_stdio(0);
  int tt = 1; 
  while(tt--) solve();
  return 0;
}