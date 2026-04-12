#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int maxx = 1e5 + 7;
const int Inf = 1 << 30;
const LL INF = 1LL << 60;
typedef pair <int, int> PR;
priority_queue <PR> qua;
#define mst(x) memset(x, 0, sizeof(x))
vector <int> vec;
LL n, x;
LL g[55]; //总厚度
LL f[55]; //p的厚度

void Init() {
	mst(g);
	mst(f);
	scanf("%lld %lld", &n, &x);
}

int main() {
	Init();
	g[1] = 5, f[1] = 3;
	for(int i = 2; i <= 50; i++) {
		g[i] = g[i - 1] * 2 + 3;
		f[i] = f[i - 1] * 2 + 1;
	}
	LL res = 0;
	if(x <= n) res = 0;
	else {
		for(int i = n; i >= 1; i--) {
			if(x >= g[i] + n - i) {
				x -= (g[i] + n - i);
				res += f[i];
				if(x) x--, res++;
				n = i;
			}
		}
		if(x - n == 1) res++;
		else if(x - n == 2) res += 2;
		else if(x - n >= 3) res += 3;
	}
	printf("%lld\n", res);
}