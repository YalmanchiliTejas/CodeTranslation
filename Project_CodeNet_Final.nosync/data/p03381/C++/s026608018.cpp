#pragma warning(disable:4996)
#include "bits/stdc++.h"
using namespace std;

using ll = long long;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define pb push_back
#define mp make_pair
#define fill(x,y) memset(x,y,sizeof(x))
#define even(x) x % 2 == 0
#define odd(x) x % 2 != 0
#define all(x) x.begin(), x.end()
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define F first
#define S second
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

int qp(int a, ll b, int mo) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, size_t b, Ts... ts) {
	return vector<decltype(make_v<T>(b, ts...))>(a, make_v<T>(b, ts...));
}
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) {
	for (auto &e : t) fill_v(e, v);
}
// auto dp = make_v<int>(4, h, w);
// fill_v(dp, 0);

const ll INF_LL = (1ll << 60);
const int INF_INT = (int)1e9;
const ll MOD_CONST = (ll)(1e9 + 7);

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

inline tuple<ll, ll> rotate45(tuple<ll, ll> p)
{
	ll x = get<0>(p), y = get<1>(p);
	return tuple<ll, ll>(x + y, x - y);
}

int main(void)
{
	cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(20);

	int N; cin >> N;
	vector<int> as(N), nums(N);
	REP(i, N) {
		int a; cin >> a;
		as[i] = a;
		nums[i] = a;
	}
	sort(all(as));
	vector<int> c2(as.begin() + (as.size() - 2) / 2, as.begin() + (as.size() - 2) / 2 + 2);
	if (N == 2) {

	}
	set<int> l(as.begin(), as.begin() + (as.size() - 2) / 2);
	set<int> r(as.rbegin(), as.rbegin() + (as.size() - 2) / 2);
	REP(i, N) {
		int a = nums[i], ans;
		if (c2[0] == a) ans = c2[1];
		else if (c2[1] == a) ans = c2[0];
		else {
			if (c2[0] > a) {
				ans = c2[1];
			}
			else {
				ans = c2[0];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}