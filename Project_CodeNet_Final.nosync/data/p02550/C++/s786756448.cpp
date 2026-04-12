#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<unordered_map>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#include<random>
#include<queue>
using namespace std;
using lld = long long int;
using pll = pair<lld, lld>;
using lf = double;
using pff = pair<lf, lf>;
using pif = pair<int, lf>;
using pii = pair<int, int>;
using pli = pair<lld, int>;
using pil = pair<int, lld>;
using piii = pair<int, pii>;
#define M 998244353
lld n;
int x, m;
int ad[100009];
lld a[100009];
int main() {
	int i, j, k, l;
	int t = 1, tv = 0;
	//scanf("%d", &t);
	while (t--) {
		scanf("%lld %d %d", &n, &x, &m);
		lld cur = x;
		ad[x] = 1;
		a[0] = x;
		lld cycle = 0;
		int cl = -1;
		lld cn;
		lld ci;
		lld base = cur;
		lld res = 0;
		for (i = 2;i <= n; i++) {
			lld nxt = (cur * cur) % m;
			a[i - 1] = nxt;
			if (ad[nxt] == 0) {
				ad[nxt] = i;
				base += nxt;
			}
			else {
				cl = i - ad[nxt];
				cn = nxt;
				ci = ad[nxt];
				break;
			}
			cur = nxt;
		}
		//printf("%lld %lld %d\n", ci, cn, cl);
		if (ci > 0 && n - ci - cl > 0) {
			lld ds = (n - ci - cl) / cl;
			lld cbase = 0;
			res = base;
			for (i = ci; i < ci + cl; i++) {
				cbase += a[i - 1];
			}
			res += cbase * ds;
			lld dl = (n - ci - cl) % cl;
			for (i = ci; i <= ci + dl; i++) {
				res += a[i - 1];
			}
		}
		else {
			res = base;
		}
		printf("%lld\n", res);
	}
	return 0;
}