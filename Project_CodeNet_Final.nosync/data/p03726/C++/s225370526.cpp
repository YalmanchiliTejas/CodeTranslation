#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
typedef pair<pll, pll> P;
const ll INF = 1ll<<29;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int N;
set<int> g[112345];
bool cut[112345];

int main() {
	cin >> N;
	REP(i, N - 1) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		g[a].insert(b);
		g[b].insert(a);
	}
	
	queue<int> que;
	REP(i, N) if (g[i].size() == 1) que.push(i);
	
	bool ans = false;
	
	while (!que.empty()) {
		int u = que.front(); que.pop();
		if (cut[u]) continue;
		u = *g[u].begin(); // 葉の親
		if (cut[u]) continue;
		
		int cnt = 0;
		for (set<int>::iterator to = g[u].begin(); to != g[u].end(); ++to) {
			if (cut[*to]) continue;
			
			if (g[*to].size() == 1) {
				cnt++;
				cut[*to] = true;
			}
			else if (g[*to].size() == 2) que.push(*to);
		}
		
		for (set<int>::iterator to = g[u].begin(); to != g[u].end(); ++to) g[*to].erase(u);
		g[u].clear();
		cut[u] = true;
		
		if (cnt >= 2) ans = true;
	}
	
	puts(ans ? "First" : "Second");
	return 0;
}