#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;

// -------------------------------------------------------

int N, M;
vector<int> Graph[10];

int main() {
  cin >> N >> M;
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }

  int p[] = {1, 2, 3, 4, 5, 6, 7, 8};
  ll ans = 0;
  do {
    if (p[0] != 1) continue;

    bool can = true;
    rep(i, 0, N - 1) {
      int cv = p[i];
      int nv = p[i + 1];
      bool ok = false;
      for (auto e : Graph[cv]) {
        if (e == nv) {
          ok = true;
        }
      }
      if (!ok) can = false;
    }
    if (can) ++ans;
  } while (next_permutation(p, p + N));
  cout << ans << endl;
}
