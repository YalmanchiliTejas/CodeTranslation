#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int a[210][210];
struct E {
	int to, cap, co, rev;
};
vector<E> e[80010];
const int C = 40010;
void add_edge(int f, int t, int c, int ca) {
	e[f].push_back((E){t, ca, c, (int)e[t].size()});
	e[t].push_back((E){f, 0, -c, (int)e[f].size()-1});
}
long long h[80010],  d[80010];
long long prevv[80010], preve[80010];
const long long inf = 1ll << 50;
int go(int f, int t) {
	int res = 0;
	int fl = 2;
	while (fl) {
		for (int i = 0; i < t + C; i++) {
			d[i] = inf;
		}
		d[f] = 0;
		priority_queue<pair<int, int> > q;
		q.push(make_pair(0, f));
		while (q.size()) {
			int x = q.top().second, z = -q.top().first;
			q.pop();
			if (d[x] < z) continue;
			for (int i = 0; i < e[x].size(); i++) {
				E &ed = e[x][i];
				int y = ed.to;
				if (ed.cap > 0 && d[x] + ed.co + h[x] < d[y] + h[y]) {
					d[y] = d[x] + ed.co + h[x] - h[y];
					prevv[y] = x;
					preve[y] = i;
					q.push(make_pair(-d[y], y));
				}
			}
		}
		for (int i = 0; i < t + C; i++) {
			h[i] += d[i];
		}
		int v = t;
		while (v != f) {
			E &ed = e[prevv[v]][preve[v]];
			ed.cap -= 1;
			e[v][ed.rev].cap += 1;
			v = prevv[v];
		}
		res += h[t];
		--fl;
	}
	return res;
}
int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &a[i][j]);
			a[i][j] = 100000 - a[i][j];
			if (i < h - 1) {
				add_edge(i * w + j + C, i * w + w + j, 0, 1);
			}
			if (j < w - 1) {
				add_edge(i * w + j + C, i * w + j + 1, 0, 1);
			}
			add_edge(i * w + j, i * w + j + C, a[i][j], 1);
		}
	}
	long long ans = 200000 - a[0][0] - a[h-1][w-1] + 200000ll * (h + w - 3) - go(C, (h - 1) * w + w - 1);
	printf("%lld\n", ans);
	return 0;
}
