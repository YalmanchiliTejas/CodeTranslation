#include<cstdio>
#include<vector>
#include<tuple>
#include<queue>

using namespace std;

vector<pair<int, int>> map[100001];

long long ds[100001], dt[100001];
long long cs[100001], ct[100001];

const int MOD = 1000000007;

void dijk(int n, int s, long long *d, long long *c) {
	priority_queue<pair<long long, int>> H;
	for (int i = 1; i <= n; i++) d[i] = -1;
	c[s] = 1; d[s] = 0;
	H.emplace(0, s);
	long long w; int x, xx;
	while (!H.empty()) {
		tie(w, x) = H.top(); H.pop();
		if ((w*=-1) != d[x]) continue;
		for (auto &e : map[x]) {
			tie(xx, w) = e;
			if (d[xx] == -1 || d[xx] > d[x] + w) {
				d[xx] = d[x] + w;
				c[xx] = c[x];
				H.emplace(-d[xx], xx);
			}
			else if(d[xx] == d[x] + w) (c[xx] += c[x]) %= MOD;
		}
	}
	return;
}

int main() {
	int n, m, s, t, a, b, d;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &d);
		map[a].emplace_back(b, d);
		map[b].emplace_back(a, d);
	}
	dijk(n, s, ds, cs);
	dijk(n, t, dt, ct);
	vector<long long> c;
	long long D = ds[t], ans = 0, S = 0;
	for (int i = 1; i <= n; i++) {
		if (ds[i] == dt[i]) c.push_back(cs[i] * ct[i] % MOD);
		if (ds[i] * 2 >= D) continue;
		for (auto e : map[i]) {
			if (ds[i] + e.second + dt[e.first] != D) continue;
			if (dt[e.first] * 2 < D) c.push_back(cs[i] * ct[e.first] % MOD);
		}
	}
	for (auto x : c) (S += x) %= MOD;
	for (auto x : c) {
		ans = (ans + x*(S-x+MOD)) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}