#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define allg(a) (a).begin(), (a).end(), greater<int>()

using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using pii = pair<int, int>;

const int INF = 1001001001;
const int MOD = 1000000007;
const long long INFL = (1LL << 60);
const double EPS = 1e-9;

bool G[10][10];

int main() {
  int N, M;
  cin >> N >> M;
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a][b] = G[b][a] = true;
  }
  vi v(N);
  rep(i, N) v[i] = i;

  int res = 0;
  do {
    if (v[0] != 0) continue;
    bool can = true;
    rep(i, N - 1) {
      int from = v[i], to = v[i + 1];
      if (!G[from][to]) can = false;
    }
    if (can) res++;
  } while (next_permutation(all(v)));

  cout << res << endl;
}