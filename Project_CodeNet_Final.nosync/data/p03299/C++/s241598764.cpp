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
#define INF 1145141919
#define MOD 1000000007

inline void add(int &x, int v) { x += v; if (x >= MOD) x -= MOD; }
inline int mul(int x, int y) { return (1LL*x*y)%MOD; }
int modpow(int x, int k) {
  int a = 1;
  while (k) {
    if (k&1) a = mul(a, x);
    x = mul(x, x);
    k>>=1;
  }
  return a;
}

int N;
int A[100];

int V;
int dp1[100], dp2[100];
int W[100], H[100];
vector<int> G[100];

int f(int l, int r, int base) {
  int m = INF;
  for (int i=l; i<=r; i++) m = min(m, A[i]);

  int id = V++;
  W[id] = r-l+1;
  H[id] = m-base;
  assert(H[id]>0);

  int lp = -1;
  for (int i=l; i<=r; i++) {
    if (A[i] > m) {
      if (lp == -1) lp = i;
    }
    else {
      if (lp != -1) G[id].pb(f(lp, i-1, m)), lp = -1;
    }
  }
  if (lp != -1) G[id].pb(f(lp, r, m));
  return id;
}
void dfs(int x) {
  int rest = W[x];
  for (int t : G[x]) dfs(t), rest -= W[t];
  // g = 2*Πdp1[t]
  // dp1[x] = 2^(h-1) * g
  // dp2[x] = (2^rest * Π(2*dp1[t]+dp2[t])) - g
  int g = 2;
  for (int t : G[x]) g = mul(g, dp1[t]);
  dp1[x] = mul(modpow(2, H[x]-1), g);
  dp2[x] = modpow(2, rest);
  for (int t : G[x]) dp2[x] = mul(dp2[x], (mul(2, dp1[t])+dp2[t])%MOD);
  add(dp2[x], MOD-g);
  //cout<<"w="<<W[x]<<", h="<<H[x]<<", dp1="<<dp1[x]<<", dp2="<<dp2[x]<<"\n";
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N) cin >> A[i];
  vector<int> xs;
  rep(i, N) xs.pb(A[i]);
  sort(all(xs)); uniq(xs);

  int root = f(0, N-1, 0);
  dfs(root);
  cout << (dp1[root]+dp2[root])%MOD << "\n";
  return 0;
}
