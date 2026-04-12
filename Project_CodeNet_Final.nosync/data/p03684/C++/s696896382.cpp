#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
#include<iostream>
using namespace std;

#define N 100001
#define mp make_pair
#define pii pair<int, int>
#define piii pair<int, pii >
#define mp3(a, b, c) mp(a, mp(b, c))

int n;
int px[N], py[N];
int fa[N];
pii sx[N], sy[N];

int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
bool uni(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return false;
	fa[x] = y;
	return true;
}

int dist(int i, int j) {
	return min(abs(px[i] - px[j]), abs(py[i] - py[j]));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &px[i], &py[i]);
		fa[i] = i;
		sx[i] = mp(px[i], i);
		sy[i] = mp(py[i], i);
	}
	sort(sx + 1, sx + 1 + n);
	sort(sy + 1, sy + 1 + n);
	set<piii > st;
	for (int i = 1; i < n; i++) {
		st.insert(mp3(dist(sx[i].second, sx[i + 1].second), sx[i].second, sx[i + 1].second));
		st.insert(mp3(dist(sy[i].second, sy[i + 1].second), sy[i].second, sy[i + 1].second));
	}

	int ans = 0;
	while (st.size()) {
		piii now = *(st.begin());
		st.erase(now);
		int u = now.second.first, v = now.second.second;
		ans += uni(u, v) * now.first;
	}
	printf("%d", ans);
	return 0;
}