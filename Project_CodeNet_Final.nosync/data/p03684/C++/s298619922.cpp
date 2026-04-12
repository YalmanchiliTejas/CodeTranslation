#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 10;
int N;
int fa[MAXN];
struct Node {
	int x, y, i;
} A[MAXN];
struct Edge {
	int x, y, d;
};
vector<Edge> E;
ll ans;

inline int gf(int x) {
	return x == fa[x] ? x : fa[x] = gf(fa[x]);
}

int main() {
	register int i;
	scanf("%d", &N);
	for(i = 1; i <= N; ++i)
		scanf("%d%d", &A[i].x, &A[i].y), A[i].i = i, fa[i] = i;
	sort(A + 1, A + N + 1, [&](Node x, Node y) {return x.x < y.x;});
	for(i = 1; i < N; ++i)
		E.emplace_back((Edge) {A[i].i, A[i + 1].i, A[i + 1].x - A[i].x});
	sort(A + 1, A + N + 1, [&](Node x, Node y) {return x.y < y.y;});
	for(i = 1; i < N; ++i)
		E.emplace_back((Edge) {A[i].i, A[i + 1].i, A[i + 1].y - A[i].y});
	sort(E.begin(), E.end(), [&](Edge x, Edge y) {return x.d < y.d;});
	for(auto e: E) {
		int x = gf(e.x), y = gf(e.y);
		if(x != y) ans += e.d, fa[x] = y;
	}
	printf("%lld\n", ans);
	return 0;
}