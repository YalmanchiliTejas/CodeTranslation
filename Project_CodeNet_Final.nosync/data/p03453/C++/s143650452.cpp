#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10, mod = 1e9 + 7;
vector<pair<int, int> > gr[N];
long long dis[3][N], cnt[3][N];
int n, m, s, t, mark[N];
vector<pair<int, pair<int, int> > > e;
void getDis(int st, int tp) {
	dis[tp][st] = 0, cnt[tp][st] = 1;
	set<pair<int, pair<int, int> > > s;
	for (auto p : gr[st]) {
		int u = p.first, w = p.second;
		s.insert({w, {u, st}});
	}
	mark[st] = 1;
	while (!s.empty()) {
		pair<int, pair<int, int> > p = *s.begin();
		s.erase(s.begin());
		int w = p.first, v = p.second.first, par = p.second.second;
		if (mark[v]) {
			if (w == dis[tp][v])
				cnt[tp][v] = (cnt[tp][v] + cnt[tp][par]) % mod;
			continue;
		}
		mark[v] = 1;
		dis[tp][v] = w;
		cnt[tp][v] = (cnt[tp][v] + cnt[tp][par]) % mod;
		for (auto p : gr[v]) { 
			s.insert({w + p.second, {p.first, v}}); 
		}
	}
	memset(mark, 0, sizeof(mark));
	return;
}
signed main() {
	cin >> n >> m >> s >> t;
	s--, t--;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		e.push_back({w, {x, y}}), e.push_back({w, {y, x}});
		gr[x].push_back({y, w}), gr[y].push_back({x, w});
	}
	memset(dis, 127, sizeof(dis));
	getDis(s, 0), getDis(t, 1);
//	for (int i = 0; i < n; i++) {
//		cout << dis[1][i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		cout << cnt[1][i] << " ";
//	}
//	cout << endl;
	long long ans = 1ll * cnt[0][t] * cnt[0][t] % mod, d = dis[0][t];
//	cout << "ans = " << ans << endl;
	for (int i = 0; i < n; i++) {
		if (dis[0][i] + dis[1][i] == d && dis[0][i] == dis[1][i]) {
//			cout << "i = " << i << endl;
			ans = 1ll *  (ans - 1ll * cnt[0][i] * cnt[1][i] % mod * cnt[0][i] % mod * cnt[1][i] % mod + mod) % mod;
		}
	}
//	cout << "ans = " << ans << endl;
	for (auto p : e) {
		int x = p.second.first, y = p.second.second;
		if (dis[0][x] + dis[1][y] + p.first == d && dis[0][x] * 2 < d && dis[1][y] * 2 < d) {
//			cout << "HOO" << endl;
			ans = 1ll * (ans - 1ll * cnt[0][x] * cnt[1][y] % mod * cnt[0][x] % mod * cnt[1][y] % mod + mod) % mod;
		}
	}
	cout << (ans + mod) % mod << endl;
	return 0;
}
