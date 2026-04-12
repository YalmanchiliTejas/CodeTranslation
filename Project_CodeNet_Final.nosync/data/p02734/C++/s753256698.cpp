#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
const int maxn = 4003, mod = 998244353;
ll n, s, dp[maxn][maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	vi a(n);
	for(auto &i : a) cin >> i;
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; a[i] + j <= s; j++) {
			if(j==0&&j+a[i]==s) {
				(dp[i+1][j+a[i]] += (dp[i][j]*(i+1)%mod)*(n-i))%=mod;
			} else if(j==0) {
				(dp[i+1][j+a[i]] += dp[i][j]*(i+1)%mod)%=mod;
			} else if(j+a[i]==s) {
				(dp[i+1][j+a[i]] += dp[i][j]*(n-i)%mod)%=mod;
			} else {
				(dp[i+1][j+a[i]] += dp[i][j])%=mod;
			}
		}
		for(int j = 0; j <= s; j++) 
			(dp[i+1][j] += dp[i][j])%=mod;
	}
	cout << dp[n][s];
}
