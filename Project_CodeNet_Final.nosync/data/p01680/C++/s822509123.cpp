#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define resz(v, ...) (v).clear(), (v).resize(__VA_ARGS__)
#define reps(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep(i, n) reps(i, 0, n)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using Pi = pair<int, int>;
using Ti = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

struct UnionFind {
  vector<int> data;
  UnionFind(int n):data(n, -1){}
  int find(int x) {
    return data[x] < 0 ? x : data[x] = find(data[x]);
  }
  void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
  }
};

int modPow(int x, int n) {
  int res = 1;
  while(n > 0) {
    if(n&1) (res *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return res;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n, m;
  while(cin >> n >> m, n) {
    UnionFind uf(n);
    rep(i, m) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      uf.unite(a, b);
    }
    int kind = 0;
    rep(i, n) kind += (uf.find(i) == i);
    if(kind == n) cout << modPow(2, kind) << endl;
    else cout << modPow(2, kind)+1 << endl;
  }

  return 0;
}