#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T> using Graph = vector<vector<T>>;

#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define EACH(i, a) for (auto i: a)
#define ITR(x, a) for (__typeof(a.begin()) x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define endl '\n'

int N;
vector<int> tree[100005];
bool removed[100005];

void dfs(int u, int p) {
  for (auto v: tree[u]) {
    if (v == p) continue;
    dfs(v, u);
  }

  if (p != -1 && !(removed[u] || removed[p]))
    removed[u] = removed[p] = true;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  rep(i, N - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  dfs(0, -1);

  bool first = false;
  rep(i, N) first |= !removed[i];

  cout << (first ? "First":"Second") << endl;

  return 0;
}
