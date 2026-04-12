#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define MOD 998244353

int n, s;

int a[3010];
int memo[3010][3010][2];

int dp(int i, int num, int start){
	if(num == 0){
		return n-i+1;
	}

	if(i == n) return 0;

	if(memo[i][num][start] != -1) return memo[i][num][start];

	int ans = 0;
	if(start == 0){
		ans = dp(i+1, num, 0);
		ans = (ans + dp(i+1, num, 1)) % MOD;
		if(num-a[i] >= 0) ans = (ans + dp(i+1, num-a[i], 1)) % MOD;
	}else{
		ans = dp(i+1, num, 1);
		if(num-a[i] >= 0) ans = (ans + dp(i+1, num-a[i], 1)) % MOD;
	}

	return memo[i][num][start] = ans;
}

signed main(){
	cin >> n >> s;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}

	memset(memo, -1, sizeof(memo));

	cout << dp(0, s, 0) << endl;

	return 0;
}
