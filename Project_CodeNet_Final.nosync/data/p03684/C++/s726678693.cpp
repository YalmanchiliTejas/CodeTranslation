#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

typedef pair<int, int> Pi;
typedef tuple<int, int, int> Ti;
typedef vector<int> vint;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

struct UnionFind
{
  vector<int> data;
  UnionFind(){}
  UnionFind(int sz):data(sz, -1){};
  int size(int x) { return -data[find(x)]; }
  int find(int x) { return data[x] < 0 ? x : data[x] = find(data[x]); }
  bool same(int x, int y) { return find(x) == find(y); }
  int unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x != y) {
      if(data[x] > data[y]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return -data[x];
  }
};

int N;
vector<Pi> ps;
vector<Pi> vx, vy;

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N;
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    ps.emplace_back(x, y);
    vx.emplace_back(x, i);
    vy.emplace_back(y, i);
  }
  sort(all(vx));
  sort(all(vy));

  UnionFind uf(N);
  priority_queue<Ti, vector<Ti>, greater<Ti> > que;
  rep(i, N-1) {
    que.emplace(abs(vx[i+1].first-vx[i].first), vx[i+1].second, vx[i].second);
  }
  rep(i, N-1) {
    que.emplace(abs(vy[i+1].first-vy[i].first), vy[i+1].second, vy[i].second);
  }
  int ans = 0;
  while(!que.empty()) {
    Ti t = que.top(); que.pop();
    int cost, i, j;
    tie(cost, i, j) = t;
    if(!uf.same(i, j)) {
      ans += cost;
      uf.unite(i, j);
    }
  }
  cout << ans << endl;

  return 0;
}
