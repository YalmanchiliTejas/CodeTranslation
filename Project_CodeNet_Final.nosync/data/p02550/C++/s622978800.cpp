//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FIO ios_base::sync_with_stdio(false); cin.tie(0);
#define trav(x,a) for (auto& x: a)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define mem(a,v) memset((a), (v), sizeof (a))
#define endl "\n"
#define case(t) cout << "Case #" << (t) << ": "
#define reada(a, n) for (int _i = 0; _i < (n); _i++) read(a[_i])
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e6 + 5;
const double eps = 1e-9;

template<class T> void read(T& x) { cin >> x; }
template<class X, class Y> void read(pair<X,Y>& a) { read(a.first), read(a.second); }
template<class T> void read(vector<T>& x) { trav(y, x) read(y); }
template<class T, class... O> void read(T& x, O&... y) { read(x), read(y...); }

string to_string(const char& x) { return string(1,x); }
string to_string(const char*& x) { return (string)x; }
string to_string(const string& x) { return x; }
template<class T, class U> string to_string(const pair<T,U>& x) { return to_string(x.first) + " " + to_string(x.second); }
template<class T> string to_string(const vector<T>& x) { string ret = ""; bool f = 0; trav(y, x) ret += (!f ? "" : " ") + to_string(y), f = 1; return ret; }
void print() { cout << endl; }
template<class T> void pr(const T& x) { cout << to_string(x); }
template<class T, class... O> void print(const T& x, const O&... y) { pr(x); if (sizeof...(y)) pr(" "); print(y...); }


int inv[N], ifac[N], fac[N];

int add(int x, int y) { return x+y < mod ? x+y : x+y-mod; }
int sub(int x, int y) { return x-y >= 0 ? x-y : x-y+mod; }
int mul(int x, int y) { return x * 1ll * y % mod; }
template<class T, class... O> int add(T x, O... y) { return add(x, add(y...)); }
template<class T, class... O> int mul(T x, O... y) { return mul(x, mul(y...)); }
int norm(int x) { return x >= 0 ? (x < mod ? x : x-mod) : x+mod; }
int ncr(int n, int k) {
  if (n < k || k < 0) return 0;
  if (n < N) return mul(fac[n], ifac[n-k], ifac[k]);
  int r = 1;
  for (int i = 1; i <= k; i++)
    r = mul(r, n-i+1, inv[i]);
  return r;
}
int pw(int x, int y) {
  int r = 1;
  for (; y; x = mul(x, x), y /= 2)
    if (y & 1)
      r = mul(r, x);
  return r;
}

int vis[N];
ll pref[N];

int main() {
  FIO
  ll n; int x; read(n, x, mod);
  vis[x] = 1;
  int y = x;
  ll ans = x;
  vis[y] = 1, pref[1] = y;
  for (ll i = 2; i <= n; i++) {
    y = mul(y, y);
    if (!vis[y]) {
      ans += y;
      vis[y] = i;
      pref[i] = ans;
    } else {
      ll len = i - vis[y];
      ll cnt = (n-i+1) / len;
      ans += cnt * (pref[i-1] - pref[vis[y]-1]);
      i += ((n - i + 1) / len) * len;
      while (i <= n) {
        ans += y;
        y = mul(y, y);
        i++;
      }
      break;
    }
  }
  print(ans);
  return 0;
}