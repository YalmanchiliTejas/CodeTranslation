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

#define REP(i, n) for(int i = 0;i < (n);++i)
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
constexpr int MOD = 1e9 + 7; constexpr int MAX = 200020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e18;

vector<int>G[100010];

void search(int n,int par, int res, int& t,int &mx) {
	if (res > mx) {
		mx = res;
		t = n;
	}
	for (auto nxt : G[n]) {
		if (nxt == par)continue;
		search(nxt, n, res + 1, t, mx);
	}
}

int distS[100010];
int distT[100010];
void calc_dist(int n, int par, int res,int *dist) {
	dist[n] = res;
	for (auto nxt : G[n]) {
		if (nxt == par)continue;
		calc_dist(nxt, n, res + 1,dist);
	}
}
int deg[100010];

void solve() {
	int N; cin >> N;
	REP(i, N - 1) {
		int u, v; cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	int s = 0, t = 0;
	int mx = 0;
	search(0, 0, 0, s, mx);
	mx = 0;
	search(s, s, 0, t, mx);
	int mid1 = 0;
	calc_dist(s, s, 0,distS);
	calc_dist(t, t, 0, distT);
	vector<int>cnt(N + 1);
	REP(i, N) {
		cnt[distS[i]]++;
	}
	REPR(i, mx+1) {
		if (cnt[i] >= 2) {
			mid1 = i; break;
		}
	}
	REP(i, N + 1)cnt[i] = 0;
	REP(i, N + 1)distT[i] = 0;
	calc_dist(t, t, 0,distT);
	bool flag = false;

	int mid2 = 0;
	REP(i, N)cnt[distT[i]]++;
	REPR(i, mx+1) {
		if (cnt[i] >= 2) {
			mid2 = i; break;
		}
	}
	//if (mx == N - 1) {
	//	string ans;
	//	REP(i, N)ans += '1';
	//	cout << ans << endl;
	//}
	//else {
	//	string ans;
	//	REP(i, N) {
	//		if (i == 0 || i == 1)ans += '1';
	//		else if (i < mx)ans += '0';
	//		else ans += '1';
	//	}
	//	cout << ans << endl;
	//}
	//cout << mid1 << " " << mid2 << endl;
	int mid = max(mid1, mid2);
	REP(i, N) {
		if (deg[i] == 1 && i != s && i != t) {
			if (distS[i] != distT[i] && max(distS[i], distT[i])==mid)flag = true;
		}
	}
	if (!flag) {
		REP(k, N) {
			if (k == 0 || k == 1)cout << '1';
			else if (k < mid-1)cout << '0';
			else cout << '1';
		}cout << endl;
	}
	else {
		REP(k, N) {
			if (k == 0 || k == 1)cout << '1';
			else if (k < mid)cout << '0';
			else cout << '1';
		}cout << endl;
	}

}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}
