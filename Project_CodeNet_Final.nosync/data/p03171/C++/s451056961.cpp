#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
long long n, dp[N][N], a[N];

// dp[i][j] -> maximum score possible;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];

	for(int len = 1;len <= n;++len)
		for(int i=1;i<=n;++i){
			if(len == 1)dp[i][i] = a[i];
			else{
				int j = i + len - 1;
				dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
			}
		}
	cout<<dp[1][n]<<"\n";
	return 0;
}