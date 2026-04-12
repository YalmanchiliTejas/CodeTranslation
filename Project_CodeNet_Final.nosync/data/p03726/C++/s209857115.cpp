#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define pb(a) push_back
#define print(x) cout<<(x)<<endl
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), n)
#define ub(v,n) upper_bound(v.begin(), v.end(), n)
//#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
const int MOD = 998244353; const int MAX = 200020;
const double pi = acos(-1); const double EPS = 1e-12;
const ll INF = 2e18;

vector<int>G[100010];
int deg[100010];
vector<int>chi[100010];
bool used[100010];
int par[100010];
void No() {
	print("First"); exit(0);
}
void make(int n, int pre) {
	for (auto nxt : G[n]) {
		if (nxt == pre)continue;
		chi[n].push_back(nxt);
		par[nxt] = n;
		make(nxt, n);
	}
}
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
	make(0,0);
	vector<int>use;
	REP(i, N) {
		if (deg[i] == 1&&i!=0)use.push_back(i);
	}
	int cnt = 0;
	while (use.size() > 0) {
		vector<int>n_use;
		REP(i, use.size()) {
			int n = use[i];
			//DEBUG(n);
			if (used[n])continue;
			if (par[n] == n)No();
			if (used[par[n]])No();
			used[n] = used[par[n]] = true;
			cnt += 2;
			deg[par[par[n]]]--;
			if (deg[par[par[n]]] == 1)n_use.push_back(par[par[n]]);
		}
		use.clear();
		for (auto n : n_use)use.push_back(n);
	}
	if (cnt != N)No();
	print("Second");
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q;cin>>q;
	//while(q--)
	solve();
}


