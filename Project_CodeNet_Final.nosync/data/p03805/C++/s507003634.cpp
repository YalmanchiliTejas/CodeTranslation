#include <bits/stdc++.h>
using namespace std;

const double pi  = 2 * acos(0.0);
const double eps = 1e-8;

#define REP(i,a,b) for(int i=(a); i<(b);++i)
#define rep(i,n) REP(i,0,n)
#define INF (1<<31)
#define INFLL (1L<<63)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int N, M;
bool G[8][8];
int state[8];

bool all_visited(void) {
  rep(i, N) if(state[i] == 0) return false;
  return true;
}

int dfs(int nn) {
  int cnt = 0;
  state[nn] = 1; // visiting
  rep(n, N) {
    if (!G[n][nn] || state[n] != 0 || n == nn)
      continue;
    cnt += dfs(n);
  }
  cnt = cnt == 0 ? all_visited() : cnt;
  state[nn] = 0;
  return cnt;
}

int main(void) {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M;
  rep(i, 8) rep(j, 8) G[i][j] = false;
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a][b] = true;
    G[b][a] = true;
  }
  cout << dfs(0) << endl;
  return 0;
}
