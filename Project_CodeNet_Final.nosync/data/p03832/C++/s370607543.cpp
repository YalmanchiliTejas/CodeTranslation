#include <bits/stdc++.h>
using namespace std;
const int maxn = 1111, mod = 1'000'000'007;
int mul(long long a, long long b){
	return a * b % mod;
}
int xp(long long a, long long b){
	a %= mod;
	int r = 1;
	for(; b; b >>= 1, a = mul(a, a)) if(b&1) r = mul(r, a);
	return r;
}
int fat[maxn], ifat[maxn];
void init(){
	fat[0] = 1;
	for(int i = 1; i < maxn; i++) fat[i] = mul(i, fat[i - 1]);
	ifat[maxn - 1] = xp(fat[maxn - 1], mod - 2);
	for(int i = maxn - 2; i >= 0; i--) ifat[i] = mul(ifat[i + 1], i + 1);
}	
int md[maxn][maxn];
int ncr(int n, int r){
	if(n < r) return 0;
	return mul(fat[n], mul(ifat[r], ifat[n - r]));
}
int dp[maxn][maxn];
int solve(int p, int k){
	if(p < 0) return 0;
	if(p == 0) return 1;
	if(dp[p][k] != -1) return dp[p][k];
	return dp[p][k] = mul(ncr(p - 1, k - 1), solve(p - k, k));
}
int main(){
	memset(dp, -1, sizeof(dp));
	init();
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	vector<int> f(n + 1, 0), nf;
	for(int j = a; j <= b; j++){
		md[j][0] = 1;
		for(int k = 1; k <= d; k++){
			md[j][k] = mul(md[j][k - 1], ifat[j]);
		}
	}
	f[0] = 1;
	for(int i = a; i <= b; i++){
		nf = f;
		for(int j = c; j * i <= n && j <= d; j++){
			for(int k = 0; k + j * i <= n; k++){
				int ways = solve(j * i, i);
				nf[k + j * i] += mul(ways, mul(ncr(k + j*i, j * i), f[k]));
				if(nf[k + j * i] >= mod) nf[k + j*i] -= mod;
			}
		}
		f = nf;
	}
	cout << f[n] << endl;
	return 0;
}
