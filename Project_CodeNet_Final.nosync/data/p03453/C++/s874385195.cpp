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
std::random_device rd;
std::mt19937 mt(rd());
constexpr int MOD = 1e9 + 7; constexpr int MAX = 200020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e18;

struct edge { int to, cost; };
int V;//頂点数
vector<edge>G[MAX];

void dijkstra(int s,vector<int>&cnt,vector<int> &d) {
	//cnt[s] = 1;
	priority_queue<P, vector<P>, greater<P>>que;
	REP(i, V)d[i] = INF;
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				//cnt[e.to] += cnt[v];
				//cnt[e.to] %= MOD;
				que.push(P(d[e.to], e.to));
			}
			else if (d[e.to] == d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				//cnt[e.to] += cnt[v];
				//cnt[e.to] %= MOD;
				//que.push(P(d[e.to], e.to));
			}
		}
	}
}
vector<edge>g[100010];
void count(vector<int>&cnt, const vector<int>&d,int s) {
	REP(i, V)g[i].clear();
	REP(i, V) {
		for (auto e : G[i]) {
			int nxt = e.to;
			if (d[nxt] == d[i] + e.cost) {
				g[i].push_back(e);
			}
		}
	}
	priority_queue<P,vector<P>,greater<P>>que;
	cnt[s] = 1;
	que.push({ 0,s });
	vector<bool>vis(V);
	vis[s] = true;
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int now = p.second;
		for (auto e : g[now]) {
			int nxt = e.to;
			//if (vis[nxt])continue;
			cnt[nxt] += cnt[now];
			cnt[nxt] %= MOD;
			if (!vis[nxt]) {
				vis[nxt] = true;
				que.push({ d[nxt],nxt });
			}
		}
	}
}

void solve() {
	int N, M; cin >> N >> M;
	int s, t; cin >> s >> t;
	s--, t--;
	REP(i, M) {
		int u, v; cin >> u >> v;
		u--, v--;
		int C; cin >> C;
		G[u].push_back({ v,C });
		G[v].push_back({ u,C });
	}
	V = N;
	vector<int>cntS(N), cntT(N);
	vector<int>dS(N), dT(N);
	dijkstra(s, cntS, dS);

	dijkstra(t, cntT, dT);
	
	count(cntS, dS, s);
	//print_space(cntS);
	count(cntT, dT, t);
	//print_space(cntT);
	ll ans = cntT[s] * cntS[t] % MOD;
	//print(ans);
	int D = dT[s];
	//print(D);
	REP(i, N) {
		if (dS[i] + dT[i] == D && dS[i] == D / 2 && dT[i] == D / 2) {
			ans = (ans - cntS[i] * cntS[i] % MOD*cntT[i] % MOD*cntT[i] % MOD + MOD) % MOD;
		}
	}
	REP(i, N) {
		for (auto e : G[i]) {
			int nxt = e.to;
			//if (nxt < i)continue;
			if (dS[i] + e.cost + dT[nxt] != D)continue;
			if (dS[i] < (D+1) / 2 && dT[nxt] < (D+1) / 2) {
				//pe(i + 1); print(nxt + 1);
				ans = (ans - cntS[i] * cntS[i] % MOD*cntT[nxt] % MOD*cntT[nxt] % MOD + MOD) % MOD;
			}
		}
	}
	print(ans%MOD);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}

