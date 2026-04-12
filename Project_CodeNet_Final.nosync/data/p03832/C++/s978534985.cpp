#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint fact[2005], fact_i[2005];

llint pow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (pow(a, n-1)%mod)) % mod;
	}
	else{
		return pow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < 2005; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	for(int i = 0; i < 2005; i++){
		fact_i[i] = pow(fact[i], mod-2);
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_i[k], ret %= mod;
	ret *= fact_i[n-k], ret %= mod;
	return ret;
}

llint N;
llint A, B, C, D;
llint dp[1005][1005];

int main(void)
{
	cin >> N;
	cin >> A >> B >> C >> D;
	make_fact();
	
	dp[0][0] = 1;
	llint val;
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= N; j++){
			if(dp[i][j] == 0) continue;
			for(int k = 0; j + (i+1)*k <= N; k++){
				if(k != 0 && (i+1 < A || i+1 > B)) break;
				if(k != 0 && (k < C || k > D)) continue;
				val = 1;
				for(int l = 0; l < k; l++){
					val *= comb(N-j-(i+1)*l, i+1);
					val %= mod;
				}
				val *= fact_i[k];
				val %= mod;
				dp[i+1][j+(i+1)*k] += (dp[i][j] * val) % mod;
				dp[i+1][j+(i+1)*k] %= mod;
			}
		}
	}
	
	cout << dp[N][N] << endl;
	return 0;
}