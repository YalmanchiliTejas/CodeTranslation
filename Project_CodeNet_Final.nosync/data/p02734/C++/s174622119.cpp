#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	998244353
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

const int N = 3010;

int dp[N][N];

int32_t main(){
	int n, s;
	cin >> n >> s;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	int b[s+2] = {0};
	
	for(int i = 1; i <= n; i++){
		dp[i][a[i-1]] = i;
		for(int j = a[i-1]+1; j <= s; j++){
			dp[i][j] = b[j-a[i-1]];
		}
		for(int j = 0; j <= s; j++)
			b[j] = (b[j] + dp[i][j]) % MOD;
	}

	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		ans = (ans + (dp[i][s] * (n-i+1)) % MOD) % MOD;
	}
	
	cout << ans << endl;
	
	return 0;
}

