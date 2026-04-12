//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>
#include<array>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), (n))
#define ub(v,n) upper_bound(v.begin(), v.end(), (n))
#define int long long
//#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>pii;
typedef array<int, 3> arr3;
std::random_device rd;
std::mt19937 mt(rd());
constexpr ll MOD = 1e9 + 7; constexpr int MAX = 2000020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e18;
void y(bool c) { if (c)print("Yes"); else print("No"); };

long long gcd(long long x, long long y) {
	long long m = max(x, y), n = min(x, y);
	if (m%n == 0)return n;
	else return gcd(m%n, n);
}
const int mod = 1000000007;
//const int mod = 998244353;
struct mint {
	ll x; // typedef long long ll;
	mint(ll x = 0) :x((x%mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const { return pow(mod - 2); }
	mint& operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }


ll A[200020];
ll L[200020][2], R[200020][2];
ll dpL[200020][2], dpR[200020][2];
ll B[200020];
ll cum[200020];
void solve() {
	int N; cin >> N;
	REP(i, N)cin >> A[i];
	REP(i, N)B[N-i-1] = A[i];
	REP(i, N) {
		cum[i + 1] = cum[i];
		if (i % 2 == 0)cum[i + 1] += A[i];
	}
	for (int i = 0; i < N; i += 2) {
		L[i][0] += A[i];
		if(i+1<N)L[i][1] += A[i + 1];
		L[i+2][0] += L[i][0];
		L[i+2][1] += L[i][1];

		R[i][0] += B[i];
		if (i + 1<N)R[i][1] += B[i + 1];
		R[i + 2][0] += R[i][0];
		R[i + 2][1] += R[i][1];
	}
	for (int i = 0; i < N; i += 2) {
		dpL[i + 2][0] = dpL[i][0] + A[i];
		dpL[i + 2][1] = max(dpL[i][1] + A[i + 1], dpL[i][0] + A[i + 1]);


		dpR[i + 2][0] = dpR[i][0] + B[i];
		dpR[i + 2][1] = max(dpR[i][1] + B[i + 1], dpR[i][0] + B[i + 1]);
	}

	if (N % 2 == 0) {
		print(max(dpL[N][0], dpL[N][1]));
		return;
	}
	else {
		ll ans = -1e18;
		for (int i = 0; i < N; i += 2) {
			ll res = max(dpL[i][0], dpL[i][1]);
			res += max(dpR[N - i - 1][0], dpR[N - i - 1][1]);
			ans = max(ans, res);
		}
		for (int i = 0; i < N-2; i += 2) {
			ll res = max(dpL[i][0], dpL[i][1]);

			res += cum[N] - cum[i + 2];
			ans = max(ans, res);
		}
		for (int i = 2; i < N; i += 2) {
			ll res = max(dpR[N - 1 - i][0], dpR[N - i - 1][1]);
			res += cum[i - 1];
			ans = max(ans, res);
		}
		print(ans);
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}


