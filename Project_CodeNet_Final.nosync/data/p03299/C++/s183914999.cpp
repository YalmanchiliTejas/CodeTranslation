#include <cstdio>
#include <algorithm>
#define N 102
#define pi pair<int,int>
#define mkp make_pair
#define fi first
#define se second

using namespace std;

const int mod = 1e9 + 7;

int n;
int a[N];

int quick_pow(int ,int);
pi solve(int ,int ,int);

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	pi ans = solve(1, n, 0);
	printf("%d\n", (1ll * ans.fi + ans.se * 2 % mod) % mod);
	return 0;
}

int quick_pow(int x, int y){
	int res = 1;
	for(; y; y >>= 1, x = 1ll * x * x % mod)
		if(y & 1) res = 1ll * res * x % mod;
	return res;
}

pi solve(int l, int r, int h){
	if(l > r) return mkp(0, 0);
	if(l == r) return mkp(0, quick_pow(2, a[l] - h - 1));
	int mn = 999999999;
	for(int i = l; i <= r; ++i) mn = min(mn, a[i]);
	int f[2] = {1, 1};
	for(int i = l; i <= r; ++i)
		if(a[i] - mn){
			int pos = i;
			while(pos + 1 <= r && a[pos + 1] - mn) ++pos;
			pi res = solve(i, pos, mn);
			f[0] = 1ll * f[0] * ((1ll * res.fi + 1ll * res.se * 4 % mod) % mod) % mod;
			f[1] = 1ll * f[1] * res.se % mod * 2 % mod; i = pos;
		}
		else f[0] = 1ll * f[0] * 2 % mod;
	f[0] = (f[0] + (1ll * mod - 1ll * f[1] * 2 % mod) % mod) % mod;
	f[1] = 1ll * f[1] * quick_pow(2, mn - h - 1) % mod;
	return mkp(f[0], f[1]);
}