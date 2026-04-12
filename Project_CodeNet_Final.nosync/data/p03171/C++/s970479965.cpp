#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
ll INF = pow(10,15);

vector<ll> a;
vector<vector<ll>> dp(3010, vector<ll>(3010, INF));
ll solve1(int i, int j);
ll solve2(int i, int j);

ll solve1(int i, int j){
	if(dp[i][j] != INF){
		return dp[i][j];
	}
	if(j - i == 0){
		dp[i][j] = a[i];
	}else if(j - i == 1){
		if(a[i] > a[j]) dp[i][j] = a[i] - a[j];
		else dp[i][j] = a[j] - a[i]; 
	}else{
		ll c1 = a[i] + solve2(i+1,j);
		ll c2 = a[j] + solve2(i,j-1);
		if(c1 > c2) dp[i][j] = c1;
		else dp[i][j] = c2;
	}
	return dp[i][j];
}

ll solve2(int i, int j){
	if(dp[i][j] != INF){
		return dp[i][j];
	}
	if(j - i == 0){
		dp[i][j] = a[i];
	}else if(j - i == 1){
		if(a[i] < a[j]) dp[i][j] = a[i] - a[j];
		else dp[i][j] = a[j] - a[i]; 
	}else{
		ll c1 = solve1(i+1,j) - a[i];
		ll c2 = solve1(i,j-1) - a[j];
		if(c1 < c2) dp[i][j] = c1;
		else dp[i][j] = c2;
	}
	return dp[i][j];
}

int main(){
	int n;
	cin >> n;
	a.resize(n);
	rep(i,n) cin >> a[i];
	cout << solve1(0,n-1) << endl;
	return 0;
}