#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint n;
llint a[105], b[105];
llint num[105][105];
llint dp[105];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i]--;
	
	llint mul = 1;
	for(int i = 1; i <= n; i++){
		mul *= modpow(2, max(0LL, a[i] - max(a[i-1], a[i+1]))), mul %= mod;
		a[i] = min(a[i], max(a[i-1], a[i+1]));
	}
	
	for(int i = 1; i <= n-1; i++) b[i] = min(a[i], a[i+1]);
	
	for(int l = 1; l <= n-1; l++){
		for(int r = 1; r <= n-1; r++){
			if(l > r) continue;
			llint sum = 0;
			for(int i = l-1; i <= r; i++){
				if(b[i+1] >= b[i]) sum += b[i+1]-b[i];
				else{
					llint d = b[i]-b[i+1], x = min(sum, d);
					num[l][r] += x, num[l][r] %= mod-1, sum -= x;
				}
			}
		}
	}
	
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++){
			dp[i] += dp[j] * modpow(2, num[j+1][i-1]) % mod;
			dp[i] %= mod;
		}
	}
	
	llint ans = dp[n];
	ans *= mul, ans %= mod;
	ans *= 2, ans %= mod;
	cout << ans << endl;
	
	return 0;
}