#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 3003

using namespace std;

int mod;
int C[N][N], S[N][N], pw[N];

void init(int);
int quick_pow(int ,int, int);

int main(){
	int n; cin >> n >> mod; init(n + 1);
	int ans = 0;
	for(int i = 0; i <= n; ++i){
		int sum = 0, po = quick_pow(2, n - i, mod), tmp = 1;
		for(int j = 0; j <= i; ++j, tmp = 1ll * po * tmp % mod)
			(sum += 1ll * S[i + 1][j + 1] * pw[n - i] % mod * tmp % mod) %= mod;
		sum = 1ll * sum * C[n][i] % mod;
		(ans += i & 1 ? mod - sum : sum) %= mod;
	}
	cout << ans << endl;
	return 0;
}

void init(int n){
	for(int i = 0; i <= n; ++i)
		pw[i] = quick_pow(2, quick_pow(2, i, mod - 1), mod);
	for(int i = 0; i <= n; ++i){
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	S[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		S[i][1] = 1;
		for(int j = 2; j <= i; ++j)
			S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j] % mod) %mod;
	}
	return ;
}

int quick_pow(int x, int y, int Mod){
	int sum = 1;
	for(; y; y >>= 1, x = 1ll * x * x % Mod)
		if(y & 1) sum = 1ll * sum * x % Mod;
	return sum;
}