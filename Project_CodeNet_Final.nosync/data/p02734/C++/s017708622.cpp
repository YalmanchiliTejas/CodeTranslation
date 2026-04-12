#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define fr(i,j,k) for(i = j; i < (k); i++)
#define all(x) x.begin(), x.end()
#define el '\n'
#define remax(a,b) a = max(a, b)
#define remin(a,b) a = min(a, b)
#define sz(x) int32_t(x.size())

typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
// --------------------------------------------------------------------

const pii dxy[] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
const int mod = 998244353;
const int inf = 2e18;
const ld eps = 1e-9;
const int NN = 1e5 + 2;

const int S = 3003;
int dp[S][S][3];

string to_string(string s) {
	return '"' + s + '"';
}
string to_string(const char* s) {
	return to_string((string) s);
}
string to_string(bool b) {
	return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
	bool first = true;  string res = "{";
	for (const auto &x : v) {
		if (!first) { res += ", "; }
		first = false; res += to_string(x);
	}
	res += "}";	  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

// #define TRACE

#ifdef TRACE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void solve() {
      int i = 0, j = 0, k = 0, n = 0, s = 0; 
      cin >> n >> s;
      vi a(n);
      fr(i, 0, n) {
            cin >> a[i];
      }
      debug(a);
     fr(k, 0, 3) dp[0][a[0]][k] = 1;
      debug(s, a[0], dp[0][s][2]);
      for(i = 1; i < n; i++) {
            // copy prev states
            fr(j, 0, s+1) {
                  fr(k, 0, 3) { 
                        dp[i][j][k] = dp[i - 1][j][k];
                        if(k == 2) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][1]) % mod;
                  }
            }
            // dp transitions
            for(j = 0; j <= s - a[i]; j++) {
                  // Dim 0
                  dp[i][j + a[i]][0] += dp[i - 1][j][0];  dp[i][j + a[i]][0] %= mod;
                  // Dim 1
                  dp[i][j + a[i]][1] += dp[i - 1][j][1]; dp[i][j + a[i]][1] %= mod;
                  // Dim 2
                  dp[i][j + a[i]][2] += dp[i - 1][j][1]; dp[i][j + a[i]][2] %= mod;
            }

            dp[i][a[i]][0]++;
            dp[i][a[i]][1] += i+1; 
            dp[i][a[i]][2] += i+1;
            debug(i,dp[i][s][2]);
      }
      // cerr << dp[n-1][s][0] << ' ' << dp[n-1][s][1]<<endl;
      cout << (dp[n - 1][s][2] % mod) << el;
}

int32_t main() {
      ios::sync_with_stdio(false); cin.tie(0); 
      int T = 1; 
      // cin >> T;
      for(int tc = 1; tc <= T; tc++) {
            solve();
       }

      return 0;
}
