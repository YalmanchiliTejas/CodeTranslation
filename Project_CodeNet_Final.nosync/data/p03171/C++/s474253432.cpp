#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++17 -Wshadow -Wall sol.cpp -o  s -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vvi = vector< vi > ;
using ld = long double;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3fll;
template<typename T> T abs (T x) { return x < 0 ? -x : x; }
template<typename T> void max_self(T &a, T b) {  a = max(a, b); }
template<typename T> void min_self(T &a, T b) {  a = min(a, b); }
const int MAX = 3e3+10;
ll dp[MAX][MAX][2];
ll go(int i, int j, int p, const vector<ll> &v) {
  if(i == j)return v[i]; 
  if(i > j)return 0;
  ll &res = dp[i][j][p];
  if(res != -1)return res;
  res = v[i] + min(go(i+2, j, 1-p, v) , go(i+1, j-1, 1-p, v));
  max_self(res, v[j] + min(go(i+1, j-1, 1-p, v) , go(i, j-2, 1-p, v)));
  return res;
}
void solve(int tc) {
  int n;
  cin >> n;
  vector<ll>v(n);
  ll tot = 0;
  memset(dp, -1, sizeof(dp));
  for(auto &x: v){
    cin >> x;
    tot+=x;
  }
  ll res = go(0, n-1, 0, v);//dp[0][n-1][0]
  cout << res - (tot-res) << endl;
  // dp[i][j][k] = max points of player k in (i,j) state
}

int main() {
  int tc = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  // cin >> tc;
  for(int i = 1; i <= tc; ++i)solve(i);
  return 0;
}