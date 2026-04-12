#include "bits/stdc++.h"
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 3e3 + 9, maxV = 1e6 + 9, MOD = 998244353, SQ = 335, lg = 20, bs = 29;

ll dp[maxN];
int n, S;

void add(ll& x, ll y) {
	x += y;
	if(x >= MOD) x -= MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	#endif

	cin >> n >> S;
	for(int i = 0, inp; i < n; i++) {
		cin >> inp;
		if(inp > S) continue;
		if(inp == S) {
			add(dp[S], ll(i + 1) * (n - i));
			continue;
		}
		add(dp[S], dp[S - inp] * (n - i) % MOD);
		for(int i = S - 1; i - inp > 0; i--)
			add(dp[i], dp[i - inp]);
		add(dp[inp], i + 1);
	}
	cout << dp[S] << '\n';
}

