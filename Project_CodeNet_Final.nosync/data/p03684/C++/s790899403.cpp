#include <bits/stdc++.h>
using namespace std;

int N, X[100005], Y[100005], p[100005];

vector<int> V;
vector< pair< int, pair<int, int> > > edges;

bool cmp1(int x, int y) {
	return make_pair(X[x], Y[x]) < make_pair(X[y], Y[y]);
}

bool cmp2(int x, int y) {
	return make_pair(Y[x], X[x]) < make_pair(Y[y], X[y]);
}

int fp(int x) {
	if (p[x] == x) return x;
	else return p[x] = fp(p[x]);
}

void merge(int x, int y) {
	x = fp(x);
	y = fp(y);
	p[x]=y;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d%d", &X[i], &Y[i]);
	for (int i = 0; i < N; i++) V.push_back(i);
	sort(V.begin(), V.end(), cmp1);
	for (int i = 0; i < N - 1; i++) edges.push_back(make_pair(min(abs(X[V[i]] - X[V[i + 1]]), abs(Y[V[i]] - Y[V[i + 1]])), make_pair(V[i], V[i + 1])));
	sort(V.begin(), V.end(), cmp2);
	for (int i = 0; i < N - 1; i++) edges.push_back(make_pair(min(abs(X[V[i]] - X[V[i + 1]]), abs(Y[V[i]] - Y[V[i + 1]])), make_pair(V[i], V[i + 1])));
	for (int i = 0; i < N; i++) p[i] = i;
	sort(edges.begin(), edges.end());
	long long ans = 0;
	for (int i = 0; i < edges.size(); i++) {
		int x = edges[i].second.first, y = edges[i].second.second;
		if (fp(x) == fp(y)) continue;
		ans += edges[i].first;
		merge(x, y);
		//printf("%d %d: %d\n", x, y, edges[i].first);
	}
	printf("%lld\n", ans);
}
