#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3005;

int dp[N][N] , n , m , x , y , mod , P2[N * N] , C[N][N];

void Add(int &x , int y) {
	(x += y) %= mod;
}

int Pow(int x , int y , int mod) {
	int res = 1;
	for(;y;y >>= 1 , x = x * x  % mod) {
		if(y & 1) {
			res = res * x  % mod;
		}
	} 
	return res;
}

main(void) {
	scanf("%lld%lld" , &n , &mod);
	dp[0][0] = 1;
	C[0][0] = 1;
	for(int i = 0;i <= n;++ i) {
		for(int j = 0;j <= n;++ j) {
			Add(dp[i + 1][j] , dp[i][j] * (j + 1) % mod);
			Add(dp[i + 1][j + 1] , dp[i][j]);
		}
	}
	
	for(int i = 1;i <= n;++ i) {
		C[i][0] = 1;
		for(int j = 1;j <= n;++ j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	
	P2[0] = 1;
	for(int i = 1;i <= n * n;++ i)
	P2[i] = P2[i - 1] * 2 % mod;
		
	int ans = 0;
	for(int i = 0;i <= n;++ i) {
		int now = Pow(2 , Pow(2 , i , mod - 1) , mod) * C[n][i] % mod;
//		cerr << i <<" "<< now << endl;
		if((n - i) & 1) now = mod - now;
		int res = 0;
		for(int j = 0;j <= n - i;++ j) {
			Add(res , dp[n - i][j] * P2[i * j] % mod * now % mod);
		}
//		cerr << i <<" "<< now <<" "<< res * Pow(now , mod - 2 , mod) % mod << endl;
		Add(ans , res);
	}
	cout << ans % mod << endl;
}