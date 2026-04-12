#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

const int maxn = 3000 + 3;

int n;
ll dp[maxn][maxn], a[maxn], sum[maxn];

ll solve(int lo, int hi){
	if(hi == lo)
		return a[lo];
	if(dp[lo][hi] != -1)
		return dp[lo][hi];
	
	ll s1 = a[lo] + (sum[hi] - sum[lo]) - solve(lo + 1, hi);
	ll s2 = a[hi] + (sum[hi - 1] - sum[lo - 1]) - solve(lo, hi - 1);
	
	return dp[lo][hi] = max(s1, s2);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum[i] = sum[i - 1] + a[i];
	
	memset(dp, -1, sizeof(dp));
	ll x = solve(1, n);
	ll y = sum[n] - x;
	
	cout << x - y << endl;

	return 0;
}