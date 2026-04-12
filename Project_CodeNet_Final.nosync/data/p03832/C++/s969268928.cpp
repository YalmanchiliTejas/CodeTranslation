 // In the name of Allah
// #Isart

#include<bits/stdc++.h>

#define pii pair<int, int>
#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double

using namespace std;

const int MAXN = 1e3 + 10, mod = 1e9 + 7;
ll dp[MAXN][MAXN], f[MAXN], finv[MAXN], inv[MAXN];

ll add(ll a, ll b){
	return (a + b) % mod;
}

ll mul(ll x, ll y){
	return x * y % mod;
}

ll choose(int x, int y){
	return mul(f[y], mul(finv[x], finv[y - x]));
}

ll power(ll x, ll y){
	if(y == 1) return x;
	ll mid = power(x, y / 2);
	if(y & 1) return mul(mul(mid, mid), x);
	else return mul(mid, mid);
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	f[0] = 1;
	for(int i = 1; i < MAXN; i ++) f[i] = mul(i, f[i - 1]);
	for(int i = 0; i < MAXN; i ++) finv[i] = power(f[i], mod - 2);	
	for(int i = 1; i < MAXN; i ++) inv[i] = power(i, mod - 2);

	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= n; j ++){
			dp[i][j] = dp[i - 1][j];
			if(a <= i and i <= b){
				if(c * i > j) continue;
				ll now = 1;
				for(int t = 0; t < c - 1; t ++)
					now = mul(now, choose(i, j - t * i));
				now = mul(now, finv[c - 1]);
				for(int t = c; t <= d and t * i <= j; t ++){
					now = mul(now, choose(i, j - (t - 1) * i));
					now = mul(now, inv[t]);
					dp[i][j] = add(dp[i][j], mul(dp[i - 1][j - t * i], now));
				}
			}			
		}
	}

	cout << dp[n][n] << endl;
	return 0;	
}