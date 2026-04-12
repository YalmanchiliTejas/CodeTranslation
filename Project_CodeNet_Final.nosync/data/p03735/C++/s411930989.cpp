#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
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
typedef pair<int, int>P;
typedef array<int, 3> arr3;
std::random_device rd;
std::mt19937 mt(rd());
constexpr ll MOD = 998244353; constexpr int MAX = 2000020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e18;


void solve() {
	int N; cin >> N;
	vector<P>v(N);
	int mx = 0, mn = 1e9;
	REP(i, N) {
		cin >> v[i].first >> v[i].second;
		if (v[i].first > v[i].second)swap(v[i].first, v[i].second);
		chmax(mx, v[i].second);
		chmin(mn, v[i].first);
	}
	VSORT(v);
	//max=Rmax,min=Bmin
	ll ans = 1e18;
	{
		int Bmin = mn, Rmax = mx;
		int Bmax = 0, Rmin = 1e9;
		REP(i, N) {
			chmax(Bmax, v[i].first);
			chmin(Rmin, v[i].second);
		}
		chmin(ans, (Bmax - Bmin)*(Rmax - Rmin));
	}
	//max=Rmax,min=Rmin
	{
		if (v[0].second != mx) {
			int Mmin = v[0].second;
			int Rmax = mx, Rmin = mn;
			int Bmax = v[0].second, Bmin = v[0].second;
			FOR(i, 1, N) {
				chmax(Bmax, v[i].first);
				chmin(Bmin, v[i].first);
			}
			ll res = (Rmax - Rmin)*(Bmax - Bmin);
			//pe(Bmin); print(Bmax);
			FOR(i, 1, N) {
				chmin(Mmin, v[i].second);
				if (i == N - 1)Bmin = Mmin;
				else Bmin = min({ v[i+1].first,Mmin });
				chmax(Bmax, v[i].second);
				res = min(res, (Rmax - Rmin)*(Bmax - Bmin));
				//pe(Bmin); print(Bmax);
			}
			chmin(ans, res);
		}
	}
	print(ans);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}

