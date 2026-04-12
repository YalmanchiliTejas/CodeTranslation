#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAXN 200005
#define TRACE(x) cout<<#x<<" = "<<x<<'\n'
#define TRACE2(x, y) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<'\n'
#define TRACEA(arr, i) cout<<#arr<<"["<<i<<"]"<<" = "<<arr[i]<<'\n'
#define PRINT(arr, n) for (int iDx = 0; iDx < (n); iDx++) cout << arr[iDx] << " \n"[iDx == (n)-1]
#define SZ(x) (int)(x).size()
using namespace std;
struct ii {
	int a, b;
	bool operator < (ii o) const { return tie(a, b) < tie(o.a, o.b); }
};
struct iii {
	int a, b, c;
	bool operator < (iii o) const { return tie(a, b, c) < tie(o.a, o.b, o.c); }
};
int TC, N, M, K, Q, x, y, z;

ii hor[MAXN], ver[MAXN];
iii edge[MAXN];
long long par[MAXN];

int find(int now) { return par[now] == now? now: par[now] = find(par[now]); }

void merge(int x, int y) {
	int a = find(x);
	int b = find(y);
	par[a] = b;
}

int main() {
	#ifdef FAIRUZI10
	freopen("/home/fairuzi/Documents/CP/input.in", "r", stdin);
	#endif
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &x, &y);
		hor[i] = {x, i};
		ver[i] = {y, i};
	}
	sort(hor, hor+N);
	sort(ver, ver+N);
	
	for (int i = 0; i < N-1; i++) {
		edge[i<<1] = {hor[i+1].a-hor[i].a, hor[i+1].b, hor[i].b};
		edge[i<<1|1] = {ver[i+1].a-ver[i].a, ver[i+1].b, ver[i].b};
	}
	
	int N2 = N<<1;
	sort(edge, edge+N2);
	for (int i = 0; i < N2; i++) par[i] = i;
	
	long long ans = 0;
	for (int i = 0; i < N2; i++) {
		x = find(edge[i].b);
		y = find(edge[i].c);
		if (x != y) {
			ans += edge[i].a;
			merge(x, y);
		}
	}
	printf("%lld\n", ans);
	
	return 0;
}
