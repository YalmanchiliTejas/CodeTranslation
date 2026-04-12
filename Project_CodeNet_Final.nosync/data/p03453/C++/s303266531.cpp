#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	int S[2];
	cin >> N >> M >> S[0] >> S[1];
	S[0]--, S[1]--;
	vector< vector< pair<int, cat> > > G(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cat d;
		cin >> u >> v >> d;
		G[--u].push_back({--v, d});
		G[v].push_back({u, d});
	}
	vector<cat> dist[2], cnt[2];
	cat mod = 1000000007;
	for(int k = 0; k < 2; k++) {
		dist[k].resize(N, OVER9000);
		cnt[k].resize(N, 0);
		priority_queue< pair<cat, int>, vector< pair<cat, int> >, greater< pair<cat, int> > > q;
		dist[k][S[k]] = 0;
		q.push({0, S[k]});
		cnt[k][S[k]] = 1;
		while(!q.empty()) {
			pair<cat, int> p = q.top();
			q.pop();
			if(p.ff != dist[k][p.ss]) continue;
			ALL_THE(G[p.ss], it) if(p.ff == dist[k][it->ff]+it->ss) {
				cnt[k][p.ss] += cnt[k][it->ff];
				if(cnt[k][p.ss] >= mod) cnt[k][p.ss] -= mod;
			}
			ALL_THE(G[p.ss], it) if(dist[k][it->ff] > p.ff+it->ss) {
				dist[k][it->ff] = p.ff+it->ss;
				q.push({dist[k][it->ff], it->ff});
			}
		}
	}
	cat ans = cnt[0][S[1]] * cnt[0][S[1]] % mod;
	for(int i = 0; i < N; i++) if(dist[0][i]+dist[1][i] == dist[0][S[1]])
		if(dist[0][i] == dist[1][i]) {
			cat paths = cnt[0][i] * cnt[1][i] % mod;
			ans -= paths * paths % mod;
		}
	for(int i = 0; i < N; i++) if(dist[0][i]+dist[1][i] == dist[0][S[1]])
		ALL_THE(G[i], it) if(dist[0][it->ff]+dist[1][it->ff] == dist[0][S[1]])
			if(dist[0][i] < dist[1][i] && dist[0][it->ff] > dist[1][it->ff]) {
				if(dist[0][i] + dist[1][it->ff] + it->ss != dist[0][S[1]]) continue;
				cat paths = cnt[0][i] * cnt[1][it->ff] % mod;
				ans -= paths * paths % mod;
			}
	ans %= mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
