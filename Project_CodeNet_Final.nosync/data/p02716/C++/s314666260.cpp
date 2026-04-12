#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

constexpr ll INF = TEN(18);
constexpr int maxn = 200010;

map<int, ll> dp[maxn][2];

int main() {
	int N; cin >> N;
	V<int> a(N); rep(i, N) cin >> a[i];

	dp[0][0][0] = 0;

	auto reachable = [&](int i, int num, bool use) {
		return num + use + (N - i - use) / 2 >= N / 2;
	};

	rep(i, N) {
		rep(pr, 2) {
			for (auto p : dp[i][pr]) {
				int lnum = p.fi;
				rep(nx, 2) if (!(pr and nx)) {
					ll nval = p.se + (nx ? a[i] : 0);
					if (reachable(i, lnum, nx)) {
						if (dp[i+1][nx].count(lnum + nx)) {
							chmax(dp[i+1][nx][lnum + nx], nval);
						} else {
							dp[i+1][nx][lnum + nx] = nval;
						}
					}
				}
			}
		}
	}

	ll ans = -INF;
	rep(f, 2) {
		if (dp[N][f].count(N / 2)) {
			chmax(ans, dp[N][f][N / 2]);
		}
	}

	cout << ans << endl;

	return 0;
}
