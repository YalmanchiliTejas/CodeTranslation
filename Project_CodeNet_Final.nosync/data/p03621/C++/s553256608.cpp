#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)
#define Forr(i, j, k) for(int i = j; i >= k; i--)

const int N = 10010;
const int Mod = 998244353;

void add(int &x, int y){
	x += y;
	if(x >= Mod) x -= Mod;
}

int mul(int x, int y){
	return (long long)x * y % Mod;
}

int Pow(int x, int e){
	int ret = 1;
	while(e){
		if(e & 1) ret = mul(ret, x);
		x = mul(x, x);
		e >>= 1;
	}
	return ret;
}

using namespace std;

int fac[N], rfac[N];

void init(int n){
	fac[0] = 1;
	For(i, 1, n) fac[i] = mul(fac[i - 1], i);
	rfac[n] = Pow(fac[n], Mod - 2);
	Forr(i, n, 1) rfac[i - 1] = mul(rfac[i], i);
}

char S[N], T[N];
int n, m;
int dp[N][N], f[N];

int main(){
	scanf("%s%s", S + 1, T + 1);
	int l = strlen(S + 1);
	For(i, 1, l) if(S[i] == T[i] && S[i] == '1') ++m; else if(S[i] == '1') ++n;
	
	dp[n][m] = 1;
	Forr(i, n, 0) Forr(j, m, 0){
		long long v = dp[i][j];
		if(!v) continue;
		if(i) add(dp[i - 1][j], v * i * i % Mod);
		if(j) add(dp[i][j - 1], v * i * j % Mod);
	}

	init(m + n);

	int ans = 0;
	For(i, 0, m) add(ans, mul(mul(dp[0][i], fac[i]), mul(fac[n + m], rfac[n + m - i])));
	printf("%d\n", ans % Mod);

	return 0;
}