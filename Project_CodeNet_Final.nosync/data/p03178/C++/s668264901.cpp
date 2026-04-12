#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
string s;
int n, k;
ll dp[10010][110][2];	
ll getmod(ll a, ll b, ll mod){
	ll ans = 1;
	while(b){
		if(b & 1){
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}
ll fun(int a, int d, int t){
	if(a == n){
		if(d == 0)
			return 1;
		return 0;
	}
	if(dp[a][d][t] != -1)
		return dp[a][d][t];
	dp[a][d][t] = 0;
	int x = (s[a] - '0');
	int lim = (t == 1) ? (s[a] - '0') : 9;
	for(int i = 0; i <= lim; i++){
		int tt = 0;
		if(i == x)
			tt = t;
		ll dig = i;
		dp[a][d][t] = (dp[a][d][t] + fun(a + 1, (d + dig) % k, tt)) % MOD;
	}
	return dp[a][d][t];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	n = s.length();
	cin >> k;
	memset(dp, -1, sizeof(dp));
	cout << (fun(0, 0, 1) - 1 + MOD) % MOD << '\n';
}