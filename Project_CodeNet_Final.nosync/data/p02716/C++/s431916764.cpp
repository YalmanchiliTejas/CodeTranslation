#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
typedef vector<vvi> vvvi;

#define all(x) x.begin(), x.end()

const int MOD = 1000000009;
const int INF = 2e9;

//TO_STRING
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(char ch){
	string s;
	s += ch;
	return s;
}

string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + 
  	to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + 
  	to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

//DEBUG 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL //compile with -DLOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define pb push_back
#define fi first
#define se second  

int blah = 0;

bool blah_check(int n, int k) {
  if (n / 2 <= k && k <= (n + 1) / 2) return 1;
  else return 0;
}

ll help_solve(int n, int take, vll &a, map<pi, ll> &dp,const ll inf) {
  debug(n, take, ++blah);
  if (take > (n + 1) / 2) return -inf;
  if (take < n / 2) return -inf;
  if (dp.count({n, take})) {
    debug("here========================");
    return dp[{n, take}];
  } else {
    ll one = (blah_check(n - 1, take) ? help_solve(n - 1, take, a, dp, inf) : -inf);
    ll two = (blah_check(n - 2, take - 1) ? help_solve(n - 2, take - 1, a, dp, inf) + a[n] : -inf);
    ll ans = max(one, two);
    dp[{one, two}] = ans;
    return ans;
  }
}

void solve() {
  int n;
  cin >> n;
  vll a(n + 1), suf(n + 10);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  // const ll inf = 4e18;
  vvll dp(n + 1, vll(2, 0));
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      dp[i][0] = max(a[i] + (i - 2 >= 0 ? dp[i - 2][0] : 0), dp[i - 1][1]);
      dp[i][1] = dp[i][0];
      debug(i, dp[i]);
    } else {
      dp[i][1] = a[i] + (i - 2 >= 0 ? dp[i - 2][1] : 0);
      dp[i][0] = max(a[i] + (i - 2 >= 0 ? dp[i - 2][0] : 0), 
        dp[i - 1][0]);
    }
  }
  debug(dp);
  // for (int i = n; i >= 1; i--) {
  //   suf[i] = suf[i + 1] + a[i];
  // }
  // map<pi, ll> dp;
  // dp[{1, 0}] = 0;
  // dp[{1, 1}] = a[1];
  // dp[{2, 0}] = -inf;
  // dp[{2, 1}] = max(a[1], a[2]);
  // dp[{2, 2}] = -inf;
  // ll ans = help_solve(n, n / 2, a, dp, inf);
  // cout << ans << endl;
  cout << max(dp[n][1], dp[n][0]) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);	
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
} 