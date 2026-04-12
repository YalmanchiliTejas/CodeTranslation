#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define i64 long long int

struct mod_arith {
	int mod;
	mod_arith() {
		mod = 1000000007;
	}
	void set_mod(int _mod) { mod = _mod; }
	int add(int x, int y) { return (x + y) % mod; }
	int sub(int x, int y) { return (x - y + mod) % mod; }
	int mul(int x, int y) { return (int)((long long int)x*y%mod); }
	int pw(int x, i64 y) {
		int r = 1;
		while (1) {
			if (y & 1)r = mul(r, x);
			if (y >>= 1)x = mul(x, x);else
				break;
		}
		return r;
	}
};

mod_arith ma;

int dp[111],h[111];
int h2[111], m, n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
		h2[i] = h[i];
	}
	m = n + 1;
	h2[n] = 1;
	sort(h2, h2 + m);
	m = unique(h2, h2 + m) - h2;
	for (int i = 0; i < n; i++) {
		h[i] = lower_bound(h2, h2 + m, h[i])-h2;
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; i + j <= n; j++) {
			i64 cur = 0;
			for (int H = 0; H < m - 1; H++) {
				int S = i, E = i + j;
				while (1) {
					for (; S < E && h[S] <= H; S++);
					if (S == E)break;
					int T = S;
					for (;T < E && h[T] > H; T++);
					bool flag = true;
					if (S == i && (i > 0 && h[i - 1] > H))flag = false;
					if (T == E && (E < n && h[E] > H))flag = false;
					if (flag) {
						cur += h2[H + 1] - h2[H];
					}
					S = T;
				}
			}
			dp[i + j] = ma.add(dp[i + j], ma.mul(dp[i], ma.pw(2, cur)));
		}
	}
	printf("%d\n", ma.mul(dp[n], 2));
	return 0;
}