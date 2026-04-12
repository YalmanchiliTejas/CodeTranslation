#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;
template<typename T>
struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T>>;

/////////////////////////////////////////////////////////////////////
const ll inf = 1LL<<60;

int main()
{
  int n, m; cin>>n>>m;
  vector<vector<bool>> g(n, vector<bool>(n, false));
  rep(i, m) {
    int a,b; cin>>a>>b; a--; b--;
    g[a][b] = true;
    g[b][a] = true;
  }

  vector<int> c(n);
  rep(i, n) c[i] = i;

  int ans = 0;
  do {
    if (c[0] != 0) continue;
    bool flg = true;
    for (int i=0; i<n-1; i++) {
      if (!g[c[i]][c[i+1]]) {
        flg = false;
        break;
      }
    }
    if (flg) ans++;
  } while (next_permutation(c.begin(), c.end()));
  cout << ans << endl;

  return 0;
}
