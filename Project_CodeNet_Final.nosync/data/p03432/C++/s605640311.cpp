//Created Time:2019骞?2鏈?8鏃?鏄熸湡鍏?19鏃?7鍒?0绉?
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 100005
#define mod 998244353
#define G 3
#define iG 332748118
#define add(x,y) ((x) + (y)) % mod
#define mul(x,y) 1ll * (x) * (y) % mod

using namespace std;

int n, m, len;
int f[2][N], fac[N], ifac[N], R[N], a[N], b[N], c[N];

int quick_pow(int ,int);
int C(int ,int);
void NTT(int *,int);
void init();

int main(){
	cin >> n >> m; init();
	int cur = 0, pre = 1;
	for(int i = 1; i <= n; ++i) b[i] = ifac[i + 2];
	NTT(b, 1); f[cur][0] = 1;
	for(int u = 1; u <= m; ++u){
		swap(cur, pre);
		for(int i = 0; i <= n; ++i) a[i] = mul(f[pre][i], ifac[i]);
		for(int i = n + 1; i < len; ++i) a[i] = 0;
		NTT(a, 1);
		for(int i = 0; i < len; ++i) a[i] = mul(a[i], b[i]);
		NTT(a, -1);
		for(int i = 0; i <= n; ++i){
			f[cur][i] = mul(a[i], fac[i + 2]);
			f[cur][i] = add(f[cur][i], mul(f[pre][i], C(i, 2) + i + 1));
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; ++i)
		ans = add(ans, mul(f[cur][i], C(n, i)));
	cout << ans << endl;
	return 0;
}

void init(){
	ifac[0] = fac[0] = 1;
	for(int i = 1; i <= n + 10; ++i)
		fac[i] = mul(fac[i - 1], i), ifac[i] = quick_pow(fac[i], mod - 2);
	len = 1; int l = 0;
	while(len <= n * 2) len <<= 1, ++l;
	for(int i = 0; i < len; ++i)
		R[i] = (R[i >> 1] >> 1) | ((i & 1) << (l - 1));
	return ;
}

int C(int x, int y){
	if(x < y) return 0;
	return mul(fac[x], mul(ifac[y], ifac[x - y]));
}

int quick_pow(int x, int y){
	int sum = 1;
	for(; y; y >>= 1, x = mul(x, x))
		if(y & 1) sum = mul(sum, x);
	return sum;
}

void NTT(int *x, int flag){
	for(int i = 0; i < len; ++i)
		if(i < R[i]) swap(x[i], x[R[i]]);
	for(int i = 1; i < len; i <<= 1){
		int wn = quick_pow(flag == 1 ? G : iG, (mod - 1) / (i << 1));
		for(int j = 0; j < len; j += i << 1){
			int w = 1;
			for(int k = j; k < i + j; ++k, w = mul(w, wn)){
				int p = x[k], q = mul(w, x[i + k]);
				x[k] = add(p, q); x[i + k] = add(p, mod - q);
			}
		}
	}
	if(flag == 1) return ;
	int inv = quick_pow(len, mod - 2);
	for(int i = 0; i < len; ++i)
		x[i] = mul(x[i], inv);
	return ;
}