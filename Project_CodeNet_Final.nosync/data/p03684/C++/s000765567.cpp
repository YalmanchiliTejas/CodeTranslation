#include <iostream>
#include <queue>
#include <algorithm>
#define REP(i, a, n) for(int i = ((int) a); i < ((int) n); i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct edge {
  int a, b, d;
  bool operator<(const edge e) const {
    return d > e.d;
  }
};

class UnionFind {
  vector<int> a;
public:
  UnionFind(int n) { REP(i, 0, n) a.push_back(i); }
  int find(int i) { return a[i] == i ? i : (a[i] = find(a[i])); }
  bool unite(int i, int j) {
    if(find(i) == find(j)) return false;
    a[find(i)] = find(j);
    return true;
  }
};

int N;
pii X[100000], Y[100000];

int main(void) {
  cin >> N;
  REP(i, 0, N) {
    cin >> X[i].fi >> Y[i].fi;
    X[i].se = i;
    Y[i].se = i;
  }

  sort(X, X + N);
  sort(Y, Y + N);

  priority_queue<edge> q;
  REP(i, 0, N - 1) {
    q.push((edge) { X[i].se, X[i + 1].se, X[i + 1].fi - X[i].fi });
    q.push((edge) { Y[i].se, Y[i + 1].se, Y[i + 1].fi - Y[i].fi });
  }

  UnionFind uf(N);
  ll ans = 0;
  while(q.size()) {
    edge e = q.top();
    q.pop();
    if(uf.unite(e.a, e.b)) ans += e.d;
  }
  cout << ans << endl;

  return 0;
}
