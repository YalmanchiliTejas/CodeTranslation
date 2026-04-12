#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF_LL (ll)1e18
#define INF (int)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second
using ll = long long;
using ld = long double;
using PII = pair<int, int>;
using PIII = pair<int, PII>;
using PLL = pair<ll, ll>;
using PLLL = pair<ll, PII>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

int N, M;
int S, T;
vector<PLLL> G[114514];
vector<PII> edge;
ll ue[2][214514] = {}, uv[2][114514] = {};
ll d[114514] = {}, d2[114514] = {};

const ll mod = 1e9+7;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> S >> T; S--; T--;
	REP(i, M){
		int u, v, d;
		cin >> u >> v >> d; u--; v--;
		G[u].push_back({d, {v, i}});
		G[v].push_back({d, {u, i}});
		edge.push_back({u, v});
	}
	fill(d, d+114514, INF_LL);
	priority_queue<PLL, vector<PLL>, greater<PLL> > pq;
	d[S] = 0;
	pq.push({0, S});
	while(pq.size()){
		ll dd = pq.top().fs, v = pq.top().sc; pq.pop();
		if(dd > d[v]) continue;
		REP(i, G[v].size()){
			if(d[G[v][i].sc.fs] > d[v]+G[v][i].fs){
				d[G[v][i].sc.fs] = d[v]+G[v][i].fs;
				pq.push({d[G[v][i].sc.fs], G[v][i].sc.fs});
			}
		}
	}
	uv[0][T] = 1;
	pq.push({0, T});
	fill(d2, d2+114514, INF_LL);
	d2[T] = 0;
	while(pq.size()){
		ll dd = pq.top().fs, v = pq.top().sc; pq.pop();
		REP(i, G[v].size()){
			if(d[G[v][i].sc.fs] == d[v]-G[v][i].fs){
				ue[0][G[v][i].sc.sc] += uv[0][v];
				uv[0][G[v][i].sc.fs] += uv[0][v];
				ue[0][G[v][i].sc.sc] %= mod;
				uv[0][G[v][i].sc.fs] %= mod;
				if(d2[G[v][i].sc.fs] == INF_LL)
					pq.push({dd+G[v][i].fs, G[v][i].sc.fs});
				d2[G[v][i].sc.fs] = dd+G[v][i].fs;
			}
		}
	}
	uv[1][S] = 1;
	pq.push({0, S});
	fill(d, d+114514, INF_LL);
	d[S] = 0;
	while(pq.size()){
		ll dd = pq.top().fs, v = pq.top().sc; pq.pop();
		REP(i, G[v].size()){
			if(d2[G[v][i].sc.fs] == d2[v]-G[v][i].fs){
				ue[1][G[v][i].sc.sc] += uv[1][v];
				uv[1][G[v][i].sc.fs] += uv[1][v];
				ue[1][G[v][i].sc.sc] %= mod;
				uv[1][G[v][i].sc.fs] %= mod;
				if(d[G[v][i].sc.fs] == INF_LL)
					pq.push({dd+G[v][i].fs, G[v][i].sc.fs});
				d[G[v][i].sc.fs] = dd+G[v][i].fs;
			}
		}
	}

	ll res = (uv[0][S]*uv[0][S])%mod;
	REP(i, N){
		if(d[i] == d2[i]){
			ll mul = uv[0][i]*uv[1][i]%mod;
			res = (res-mul*mul%mod+mod)%mod;
		}
	}
	REP(i, M){
		long double dd = (long double)d[T]/2;
		int u = edge[i].fs, v = edge[i].sc;
		if(min((ld)d[u], (ld)d[v]) < dd && dd < max((ld)d[u], (ld)d[v])){
			ll mul = ue[0][i]*ue[1][i]%mod;
			res = (res-mul*mul%mod+mod)%mod;
		}
	}
	cout << res << endl;
}
