#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int Mod = 1000000007;
ll fact[1010],fact_inv[1010];

ll exp(ll a,ll b) {
	if (b == 0) return 1;
	else if (b == 1) return a;
	else {
		ll c = exp(a,b/2);
		if (b%2) return (((c*c)%Mod)*a)%Mod;
		else return (c*c)%Mod;
	}
}

ll combi(ll a,ll b) {
	return (((fact[a]*fact_inv[b])%Mod)*fact_inv[a-b])%Mod;
}

int main() {
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	vector<vector<ll>> dp(1010,vector<ll>(1010,0));

	fact[0] = 1;
	for (int i = 1;i < 1010;++i) fact[i] = (fact[i-1]*i)%Mod;
	for (int i = 0;i < 1010;++i) fact_inv[i] = exp(fact[i],Mod-2);

	dp[a-1][0] = 1;
	for (int i = a;i <= b;++i) {
		for (int j = 0;j <= n;++j) {
			if (dp[i-1][j] == 0) continue;
			dp[i][j] += dp[i-1][j];
			dp[i][j] %= Mod;
			for (int k = c;k <= min((n-j)/i,d);++k) {
				dp[i][j+i*k] += (((((((dp[i-1][j]*fact[n-j])%Mod)*fact_inv[n-j-i*k])%Mod)*exp(fact_inv[i],k))%Mod)*fact_inv[k])%Mod;
				dp[i][j+i*k] %= Mod;
			}
		}
	}
	
	cout << dp[b][n] << endl;

	return 0;
}