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
int ans;

bool visited[10];

void dfs(int cur) {
  bool finish = true;
  visited[cur] = true;
  for (auto e : Graph[cur]) {
    if (visited[e]) continue;

    dfs(e);
    finish = false;
  }

  if (finish) {
    bool allfinished = true;
    repe(i, 1, N) {
      if (!visited[i]) {
        allfinished = false;
      }
    }
    if (allfinished) ++ans;
  }

  visited[cur] = false;
}

int main() {
  cin >> N >> M;
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }

  dfs(1);

  cout << ans << endl;
}
