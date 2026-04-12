#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<cstring>
#include<complex>
#include<bitset>
#include<iostream>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Q;
typedef complex<double> C;
#define cx real()
#define cy imag()
const ll INF = 1LL << 60;
const double DINF = 1e30;
const ll mod = 1000000007;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, -1, 0, 1};
const C I = C(0, 1);
const double EPS = 1e-10;
const ll NCK_MAX = 510000;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1, y = 0; return a;
  }
  ll q = a/b, g = extgcd(b, a - q*b, x, y);
  ll z = x - q * y;
  x = y;
  y = z;
  return g;
}

ll invmod (ll a, ll m) { // a^-1 mod m
  ll x, y;
  extgcd(a, m, x, y);
  x %= m;
  if (x < 0) x += m;
  return x;
}

ll *fac, *finv, *inv;

void nCk_init(ll mod) {
  fac = new ll[NCK_MAX];
  finv = new ll[NCK_MAX];
  inv = new ll[NCK_MAX];
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (ll i = 2; i < NCK_MAX; i++) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = mod - inv[mod%i] * (mod / i) % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}

ll nCk(ll n, ll k, ll mod) {
  if (fac == NULL) nCk_init(mod);
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

template <typename T>
class Zip {
  vector<T> d;
  bool flag;
public:
  Zip() {
    flag = false;
  }
  void add(T x) {
    d.push_back(x);
    flag = true;
  }
  ll getNum(T x) { // T need to have operator < !!
    if (flag) {
      sort(d.begin(), d.end());
      d.erase(unique(d.begin(), d.end()), d.end());
      flag = false;
    }
    return lower_bound(d.begin(), d.end(), x) - d.begin();
  }
  ll size() {
    if (flag) {
      sort(d.begin(), d.end());
      d.erase(unique(d.begin(), d.end()), d.end());
      flag = false;
    }
    return (ll)d.size();
  }
};

/**** Union Find ****/

class UnionFind {
  vector<ll> par, rank; // par > 0: number, par < 0: -par
public:
  void init(ll n) {
    par.resize(n, 1); rank.resize(n, 0);
  }
  ll getSize(ll x) {
    return par[find(x)];
  }
  ll find(ll x) {
    if (par[x] > 0) return x;
    return -(par[x] = -find(-par[x]));
  }
  void merge(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      par[y] += par[x];
      par[x] = -y;
    } else {
      par[x] += par[y];
      par[y] = -x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }
  bool isSame(ll x, ll y) {
    return find(x) == find(y);
  }
};


template <typename T>
class SegmentTree {
  ll n;
  vector<T> node;
  function<T(T, T)> fun, fun2;
  bool customChange;
  T outValue, initValue;
public:
  void init(ll num, function<T(T, T)> resultFunction, T init, T out, function<T(T, T)> changeFunction = NULL) {
    // changeFunction: (input, beforevalue) => newvalue
    fun = resultFunction;
    fun2 = changeFunction;
    customChange = changeFunction != NULL;
    n = 1;
    while (n < num) n *= 2;
    node.resize(2 * n - 1, init);
    outValue = out;
    initValue = init;
  }
  void valueChange(ll num, T value) {
    num += n-1;
    if (customChange) node[num] = fun2(value, node[num]);
    else node[num] = value;
    while (num > 0) num = (num - 1) / 2, node[num] = fun(node[num * 2 + 1], node[num * 2 + 2]);
  }
  T rangeQuery(ll a, ll b, ll l = 0, ll r = -1, ll k = 0) { // [a, b)
    if (r == -1) r = n;
    if (a <= l && r <= b) return node[k];
    if (b <= l || r <= a) return outValue;
    ll mid = (l + r) / 2;
    return fun(rangeQuery(a, b, l, mid, 2*k+1), rangeQuery(a, b, mid, r, 2*k+2));
  }
};

ll n, x, len[51], pc[51];

ll dfs(ll n, ll x) {
  if (n == 0) return x >= 1 ? 1 : 0;
  if (len[n] <= x) return pc[n];
  x--;
  if (x == 0) return 0;
  ll mn = len[n-1];
  if (x <= mn) return dfs(n-1, x);
  x -= mn + 1;
  if (x == 0) return pc[n-1] + 1;
  return pc[n-1] + 1 + dfs(n-1, x);
}

int main() {
  scanf("%lld%lld", &n, &x);
  len[0] = 1, pc[0] = 1;
  for (ll i = 0; i < n; i++) len[i+1] = len[i] * 2 + 3, pc[i+1] = pc[i] * 2 + 1;
  printf("%lld\n", dfs(n, x));
}
