#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
//#define INF 1145141919
#define MOD 1000000007
inline void add(int &x, int v) { x += v; if (x >= MOD) x -= MOD; }
inline int mul(int x, int y) { return (1LL*x*y)%MOD; }

int N;
int A[100];
int dp[101][102];
int modpow(int x, int k) {
  int a = 1;
  while (k) {
    if (k&1) a = mul(a, x);
    x = mul(x, x);
    k>>=1;
  }
  return a;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N) cin >> A[i];
  vector<int> xs;
  rep(i, N) xs.pb(A[i]);
  sort(all(xs)); uniq(xs);
  int inf = xs.size();

  //dp[0][inf] = 1;
  add(dp[1][inf], 2);
  int e = 2;
  for (int k=index(xs, A[0]); k>0; k--) {
    int w = xs[k]-(k>0?xs[k-1]:0);
    add(dp[1][k], mul(e, (modpow(2, w)+MOD-1)%MOD));
    e = mul(e, modpow(2, w));
  }
  // k=0
  int w = xs[0];
  add(dp[1][0], mul(e, (modpow(2, w-1)+MOD-1)%MOD));

  int prev = A[0];
  for (int i=1; i<N; i++) {
    int vpos = index(xs, A[i]);
    if (prev >= A[i]) {
      rep(j, xs.size()) {
        // j->inf
        if (xs[j] > A[i]) add(dp[i+1][inf], mul(2, dp[i][j]));
        // j->j
        else add(dp[i+1][j], dp[i][j]);
      }
      // inf->inf
      add(dp[i+1][inf], mul(2, dp[i][inf]));
    }
    else {
      // j->j
      int e = modpow(2, A[i]-prev);
      rep(j, xs.size()) add(dp[i+1][j], mul(e, dp[i][j]));
      // inf->inf
      add(dp[i+1][inf], mul(2, dp[i][inf]));
      // inf->k
      e = 2;
      for (int k=index(xs, A[i]); k>=0 && xs[k]>prev; k--) {
        int w = xs[k]-(k>0?xs[k-1]:0);
        add(dp[i+1][k], mul(mul(e, (modpow(2, w)+MOD-1)%MOD), dp[i][inf]));
        e = mul(e, modpow(2, w));
      }
    }
    prev = A[i];
  }

  int s = 0;
  rep(i, xs.size()+1) add(s, dp[N][i]);
  cout << s << "\n";
  return 0;
}
