#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 998244353

int f[10010][10010];

char A[11111];
char B[11111];
int n, cnta, cntb;
int ans;

int S[11111];
int invs[11111];

int Pow(int a, int b){
	int tmp = 1;
	for(; b; b >>= 1, a = 1ll * a * a % MOD)
		(b & 1) && (tmp = 1ll * tmp * a % MOD);
	return tmp;
}

int C(int a, int b){
	return 1ll * S[a] * invs[b] % MOD * invs[a - b] % MOD;
}

int main(){
	scanf("%s %s", A, B);
	n = strlen(A);
	for(int i = 0; i < n; i++)
		if(A[i] == '1') (B[i] == '1') ? cnta++ : cntb++;
	S[0] = 1;
	for(int i = 1; i <= n; i++)
		S[i] = 1ll * S[i - 1] * i % MOD;
	invs[n] = Pow(S[n], MOD - 2);
	for(int i = n - 1; i >= 0; i--)
		invs[i] = 1ll * invs[i + 1] * (i + 1) % MOD;
	f[0][0] = 1;
	for(int i = 0; i <= cnta; i++){
		for(int j = 1; j <= cntb; j++){
			i && (f[i][j] = 1ll * f[i - 1][j] * i * j % MOD);
			f[i][j] = (f[i][j] + 1ll * f[i][j - 1] * j * j) % MOD;
		}
	}
	for(int i = 0; i <= cnta; i++)
		ans = (ans + 1ll * f[i][cntb] * C(cnta, i) % MOD * S[cnta - i] % MOD * S[cnta - i] % MOD * C(cnta + cntb, cnta - i)) % MOD;
	return !printf("%d\n", ans);
}