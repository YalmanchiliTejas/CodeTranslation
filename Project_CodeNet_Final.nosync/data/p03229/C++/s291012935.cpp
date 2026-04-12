#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))
#define sz(v) ((int) v.size())
using namespace std;
using i64 = long long;
using f80 = long double;
using vi32 = vector<int>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> void amax(T &x, T y) { x = max(x, y); }
template <typename T> void amin(T &x, T y) { x = min(x, y); }
template <typename T> T power(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
template <typename T, typename U> vector<U> make_vector(T&& n, U&& val) { return vector<U>(forward<T>(n), forward<U>(val)); }
template <typename T, typename... Args> decltype(auto) make_vector(T&& n, Args&&... args) { return vector<decltype(make_vector(forward<Args>(args)...))>(forward<T>(n), make_vector(forward<Args>(args)...)); }
const int INF = 1001001001;
const i64 LINF = 1001001001001001001ll;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
#endif

i64 calc(vi32 a) {
  i64 ret = 0;
  deque<int> q;
  rep(i, sz(a)) q.push_back(a[i]);
  deque<int> r;
  r.push_back(q.back());
  q.pop_back();
  int i = 1;
  while (true) {
    ret += abs(r.front() - q.front());
    r.push_front(q.front());
    q.pop_front();
    if (++i == sz(a)) break;
    ret += abs(r.back() - q.front());
    r.push_back(q.front());
    q.pop_front();
    if (++i == sz(a)) break;
    ret += abs(r.front() - q.back());
    r.push_front(q.back());
    q.pop_back();
    if (++i == sz(a)) break;
    ret += abs(r.back() - q.back());
    r.push_back(q.back());
    q.pop_back();
    if (++i == sz(a)) break;
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  vi32 a(n);
  cin >> a;
  sort(all(a));
  i64 ans = 0;
  amax(ans, calc(a));
  reverse(all(a));
  amax(ans, calc(a));
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(16);
  cerr << fixed << setprecision(16);
  solve();
  return 0;
}