#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 9;

int n, h[N], t, S, Sa[N], Sb[N], i, j, Ta[N], Tb[N];
long long ans = 8e18;

struct pa { int a, b; }p[N];
bool operator < (const pa &A, const pa &B) { return A.a < B.a; }

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &p[i].a, &p[i].b), h[++t] = p[i].a, h[++t] = p[i].b;
	sort(h + 1, h + t + 1);
	S = t = unique(h + 1, h + t + 1) - h - 1;
	for (i = 1; i <= n; ++i) {
		if (p[i].a > p[i].b) p[i].a ^= p[i].b ^= p[i].a ^= p[i].b;
		p[i].a = lower_bound(h + 1, h + t + 1, p[i].a) - h;
		p[i].b = lower_bound(h + 1, h + t + 1, p[i].b) - h;
		S = min(S, max(p[i].a, p[i].b));
	}
	sort(p + 1, p + n + 1);
	for (Sa[S + 1] = t, i = S, j = n; i; --i) for (Sa[i] = Sa[i + 1], Ta[i] = Ta[i + 1]; j && p[j].a >= i; --j) {
		if (p[j].b < Sa[i]) Sa[i] = p[j].b;
		if (p[j].a > Ta[i]) Ta[i] = p[j].a;
	}
	for (Sb[0] = t, i = 1, j = 1; i <= S; ++i) {
		for (Sb[i] = Sb[i - 1], Tb[i] = Tb[i - 1]; j <= n && p[j].a < i; ++j) {
			if (p[j].a < Sb[i]) Sb[i] = p[j].a;
			if (p[j].b > Tb[i]) Tb[i] = p[j].b;
		}
		if (1ll * (h[t] - h[min(Sb[i], Sa[i])]) * (h[max(Ta[i], Tb[i])] - h[i]) < ans) ans = 1ll * (h[t] - h[min(Sb[i], Sa[i])]) * (h[max(Ta[i], Tb[i])] - h[i]);
	}
	printf("%lld", ans);
	return 0;
}