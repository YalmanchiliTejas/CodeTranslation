#include "bits/stdc++.h"
using namespace std;

// fundamental
using ll = long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define FOR(i,s,n) for (ll i = (s); i < (n); ++i)
#define ALL(c) (c).begin(), (c).end()
#define TEN(x) ((ll)1e##x)
#define MAXC(c,x) (c = max(c, x))
#define MINC(c,x) (c = min(c, x))
const ll mod = TEN(9) + 7;

// vector
using vl = vector<ll>; using vvl = vector<vl>; using vvvl = vector<vvl>;
template<class T, size_t N, class A = size_t> auto mdv(A size = 0) -> typename enable_if<N==1, vector<T>>::type { return vector<T>(size); }
template<class T, size_t N, class A = size_t> auto mdv(A size = 0) -> vector<decltype(mdv<T, N - 1>())> { return vector<decltype(mdv<T, N - 1>())>(size); }
template<class T, size_t N, class A, class... B> auto mdv(A size, B... rest) -> typename enable_if<N!=1, vector<decltype(mdv<T, N - 1>(rest...))>>::type { return vector<decltype(mdv<T, N - 1>(rest...))>(size, mdv<T, N - 1>(rest...)); }
template<class T, class... A> auto mdv(A... size) -> decltype(mdv<T, sizeof...(size), A...>(size...)) { return mdv<T, sizeof...(size), A...>(size...); }
// template<size_t N, class A, class... B> auto mdvl(A size, B... rest) -> decltype(mdv<N, ll, A, B...>(size, rest...)) { return mdv<N, ll, A, B...>(size, rest...); }

// template<class T, class A> auto mdv(A size) -> vector<T> { return vector<T>(size); }
// template<class T, class A, class... B> auto mdv(A size, B... rest) -> vector<decltype(mdv<T>(rest...))> { return vector<decltype(mdv<T>(rest...))>(size, mdv<T>(rest...)); }

// io
template<class T> istream& operator >>(istream& is, vector<T>& vec){ for(T& x: vec) is >> x; return is; }
template<class T, class U> istream& operator >>(istream& is, pair<T, U>& p){ is >> p.first >> p.second; return is; }
template<class T> void input(T& t) { cin >> t; assert(cin); } template<class T, class... Ts> void input(T& t, Ts&... ts) { cin >> t; input(ts...); }
template<class T> void print(T&& t) { cout << t; } template<class T, class... Ts> void print(T&& t, Ts&&... ts) { cout << t; print(ts...); }
template<class T> void println(T&& t) { cout << t << endl; } template<class T, class... Ts> void println(T&& t, Ts&&... ts) { cout << t; println(ts...); }
template<class T> string join(const vector<T>& v, const string & sep) { stringstream ss; REP(i, v.size()) ss << (i != 0 ? sep : "") << v[i]; return ss.str(); }

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(50);
	ll n; cin >> n;
	vl s(n);
	REP(i, n) cin >> s[i];
	ll ans = 0;
	FOR(step, 1, (n + 1) / 2) {
		ll sum = 0;
		for(ll idx = 0; idx + step + 1 < n; idx += step) {
			if (idx >= n - 1 - idx && (n - 1) % step == 0) break; 
			sum += s[idx] + s[n - idx - 1];
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
}
