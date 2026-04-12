#include<bits/stdc++.h>
#define int long long
#define maxn 200000
#define mod 998244353
#define inf 1000000000000
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, s;
int a[3001], dp[3001][3001];

signed main()
{
	//FILEIO
	FLASH
	cin>>n>>s;
	
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		dp[i][a[i]] += i;
		for(int j = 0; j <= s; j++)
			dp[i][j] += dp[i - 1][j] + ((j >= a[i])?dp[i - 1][j - a[i]]: 0), dp[i][j] %= mod;
		ans += dp[i][s];
		ans %= mod;
	}

	cout<<ans;
}