#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	vector<int > a(n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}

	long long dp[n][n];
	memset(dp, 0, sizeof(n));

	for (int i = n-1; i >= 0; --i)
	{
		for (int j = i; j < n; ++j)
		{
			if(i==j){
				dp[i][j] = a[i];
			}
			else{
				dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
			}
		}
	}

	
	// for(int i =0;i <n ;i++){
	// 	for(int j =0; j<n ;j++){
	// 		printf("%lld ", dp[i][j]);
	// 	}
	// 	printf("\n");
	// }

	printf("%lld\n", dp[0][n-1]);

	return 0;
}