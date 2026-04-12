#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 262144
using namespace std;
struct Tree {
	long long Mn[SZ + SZ], K[SZ + SZ];
	void Add2(int nd, long long x) {
		Mn[nd] += x;
		K[nd] += x;
	}
	void Spread(int nd) {
		Add2(nd * 2, K[nd]);
		Add2(nd * 2+1, K[nd]);
		K[nd] = 0;
	}
	void UDT(int nd) {
		Mn[nd] = min(Mn[nd * 2], Mn[nd * 2 + 1]);
	}
	void Add(int nd, int b, int e, int s, int l, long long x) {
		if (b == s&&e == l) {
			Add2(nd, x);
			return;
		}
		int m = (b + e) >> 1;
		Spread(nd);
		if (s <= m)Add(nd * 2, b, m, s, min(m, l), x);
		if (l > m)Add(nd * 2 + 1, m + 1, e, max(m + 1, s), l, x);
		UDT(nd);
	}
	void Put(int nd, int b, int e, int x, long long y) {
		if (b == e) {
			Add2(nd, y - Mn[nd]);
			return;
		}
		int m = (b + e) >> 1;
		Spread(nd);
		if (x <= m)Put(nd*2, b, m, x, y);
		else Put(nd * 2 + 1, m + 1, e, x, y);
		UDT(nd);
	}
	long long Min(int nd, int b, int e, int s, int l) {
		if (b == s&&e == l)return Mn[nd];
		int m = (b + e) >> 1;
		Spread(nd);
		long long r = 1e18;
		if (s <= m)r = min(r, Min(nd * 2, b, m, s, min(m, l)));
		if (l > m)r = min(r,Min(nd * 2 + 1, m + 1, e, max(m + 1, s), l));
		UDT(nd);
		return r;
	}
}T;
int n, m;
long long D[201000];
struct AA {
	int b, c;
};
vector<AA>V[201000];
int main() {
	int i, b, e, c;
	scanf("%d%d", &n, &m);
	long long s = 0;
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &b, &e, &c);
		s += c;
		V[e].push_back({ b,c });
	}
	for (i = 1; i <= n; i++) {
		D[i] = T.Min(1, 0, n, 0, i-1);
		T.Put(1, 0, n, i, D[i]);
		for (auto &t : V[i]) {
			T.Add(1, 0, n, 0, t.b - 1, t.c);
		}
	}
	printf("%lld\n", s - T.Min(1, 0, n, 0, n));
}
