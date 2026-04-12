#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = 1e18;
//const ll MOD = 1000000007;
//const ll MOD = 998244353;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
//#define mp make_pair


template <typename T1, typename T2>
class LazySegmentTree {
public:
  using F = function<T1(T1&, T1&)>; // query_func
  using G = function<T2(T2&, T2&)>; // update_func
  using H = function<T1(T1&, T2&, int, int)>; // lazy to node (node, lazy, left, right)
  int n;
  vector<T1> node;
  vector<T2> lazy;
  T1 e1;
  T2 e2;
  F query_func;
  G update_func;
  H eval_func;

  LazySegmentTree(vector<T1> a, F query_func, G update_func, H eval_func, T1 e1, T2 e2)
    :query_func(query_func), update_func(update_func), eval_func(eval_func), e1(e1), e2(e2)
  {
    int _n = a.size();
    n = 1; while (n < _n) n *= 2;
    node.resize(2 * n - 1, e1);
    lazy.resize(2 * n - 1, e2);
    for (int i = 0; i < _n; i++) node[i + n - 1] = a[i];
    for (int i = n - 2; i >= 0; i--) {
      node[i] = query_func(node[i * 2 + 1], node[i * 2 + 2]);
    }
  }

  // k番目のノードについて遅延評価を行う
  inline void eval(int k, int l, int r) {
    if (lazy[k] != e2) { // Change
      node[k] = eval_func(node[k], lazy[k], l, r);
      if (r - l > 1) {
        lazy[2 * k + 1] = update_func(lazy[2*k + 1], lazy[k]);
        lazy[2 * k + 2] = update_func(lazy[2*k + 2], lazy[k]);
      }
      lazy[k] = e2; // Change
    }
  }

  // [a, b)をxにする
  void update(int a, int b, T2 x, int k, int l, int r) {
    // k 番目のノードに対して遅延評価を行う
    eval(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] = update_func(lazy[k], x);
      eval(k, l, r);
    }
    else {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = query_func(node[2 * k + 1], node[2 * k + 2]);
    }
  }

  T1 query(int a, int b, int k, int l, int r) {
    eval(k, l, r);
    if (b <= l || r <= a) return e1;
    if (a <= l && r <= b) return node[k];
    T1 resl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T1 resr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return query_func(resl, resr);
  }
};

ll f1(ll a, ll b) {return max(a, b);}
ll f2(ll a, ll b) {return a + b;}
ll f3(ll a, ll b, int l, int r) {return a + b;}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<pii, ll> > rla(m);
  rep (i, m) {
    int l, r;
    ll a;
    cin >> l >> r >> a;
    l--; r--;
    rla[i] = make_pair(pii(r, l), a);
  }
  sort(all(rla));
  //DEBUG_VEC(rla);
  LazySegmentTree<ll, ll> lst(vl(n + 1), f1, f2, f3, -INF, 0LL);
  int j = 0;
  rep (i, n) {
    //lst.debug(n + 1);
    //DEBUG(i);
    ll ma = lst.query(0, i + 1, 0, 0, lst.n);
    //DEBUG(ma);
    lst.update(i + 1, i + 2, ma, 0, 0, lst.n);
    while (j < m && rla[j].first.first ==  i) {
      int l = rla[j].first.second, r = rla[j].first.first;
      ll a = rla[j].second;
      //DEBUG(l); DEBUG(r);
      lst.update(l + 1, r + 2, a, 0, 0, lst.n);
      j++;
    }
  }
  cout << lst.query(0, n + 1, 0, 0, lst.n) << endl;
}
