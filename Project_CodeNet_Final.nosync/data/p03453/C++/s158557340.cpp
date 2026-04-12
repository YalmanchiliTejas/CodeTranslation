#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

const int P = 1000000007;

using namespace std;

vector<pair<int, int> > g[100001];
long long d[2][100001];
int c[2][100001];
int v[100001];

void f(int n, int x, long long d[], int c[]) {
	priority_queue<tuple<long long, int, int> > pq;
	int i;
	for (i = 1; i <= n; i++) v[i] = 0;
	c[0] = 1;
	pq.emplace(0LL, x, 0);
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (v[get<1>(p)]) {
			if (d[get<1>(p)] == -get<0>(p)) {
				c[get<1>(p)] += c[get<2>(p)];
				if (c[get<1>(p)] >= P) c[get<1>(p)] -= P;
			}
			continue;
		}
		v[get<1>(p)] = 1;
		d[get<1>(p)] = -get<0>(p);
		c[get<1>(p)] = c[get<2>(p)];
		for (auto q : g[get<1>(p)]) pq.emplace(get<0>(p) - q.second, q.first, get<1>(p));
	}
}

int main() {
	int i, j, k, n, m, p, q, r = 0;
	scanf("%d%d%d%d", &n, &m, &p, &q);
	while (m--) {
		scanf("%d%d%d", &i, &j, &k);
		g[i].emplace_back(j, k);
		g[j].emplace_back(i, k);
	}
	f(n, p, d[0], c[0]);
	f(n, q, d[1], c[1]);
	r = (long long)c[0][q] * c[0][q] % P;
	for (i = 1; i <= n; i++) {
		if (i != p && i != q && (d[0][i] << 1) == d[0][q] && (d[1][i] << 1) == d[0][q]) {
			int tt = (long long)c[0][i] * c[1][i] % P;
			r -= (long long)tt * tt % P;
			if (r < 0) r += P;
		}
		for (auto t : g[i]) if ((d[0][i] << 1) < d[0][q] && (d[0][i] + t.second << 1) > d[0][q] && d[0][i] + d[1][t.first] + t.second == d[0][q]) {
			int tt = (long long)c[0][i] * c[1][t.first] % P;
			r -= (long long)tt * tt % P;
			if (r < 0) r += P;
		}
	}
	printf("%d\n", r);
	return 0;
}
