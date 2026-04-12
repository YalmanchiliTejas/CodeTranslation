#include <iostream>
#define llint long long int
#define mod 1000000007

using namespace std;

llint N, D, X;
llint dp[2005][2005];
llint sum[2005][2005];
llint fact[2005];

llint pow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2) return ((a % mod) * (pow(a, n-1) % mod)) % mod;
	llint t = pow(a, n/2) % mod;
	return ( (t%mod) * (t%mod) ) % mod;
}

void make_fact()
{
	llint seki = 1;
	for(llint i = 1; i <= 2005; i++){
		seki *= i;
		seki %= mod;
		fact[i] = pow(seki, mod-2) % mod;
	}
}
	

llint comb(llint n, llint r)
{
	llint seki = 1;
	for(llint i = 0; i < r; i++){
		seki *= (n-i) % mod;
		seki %= mod;
	}
	seki *= fact[r];
	return seki % mod;
}

int main(void)
{
	make_fact();
	
	while(1){
		cin >> N >> D >> X;
		if(N == 0 && D == 0 && X == 0) break;
		
		for(llint n = 1; n <= N; n++) sum[n][0] = 0;
		
		for(llint m = 1; m <= N; m++){
			dp[1][m] = 1;
			if(m >= X) dp[1][m] = 0;
			sum[1][m] = (sum[1][m-1] + dp[1][m]) % mod;
		}
		
		for(llint n = 2; n <= N; n++){
			for(llint m = 1; m <= N; m++){
				if(m < n) dp[n][m] = 0;
				else dp[n][m] = sum[n-1][m-1] - sum[n-1][max((llint)0, m-X)] + mod;
				dp[n][m] %= mod;
				sum[n][m] = (sum[n][m-1] + dp[n][m]) % mod;
			}
		}
		
		llint ans = 0;
		for(llint i = 1; i <= min(D, N); i++){
			ans += ((comb(D, i)%mod) * (dp[i][N]%mod)) % mod;
			ans %= mod;
		}
		cout << ans << endl;
	}
	
	return 0;
}
		