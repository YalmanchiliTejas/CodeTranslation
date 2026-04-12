#include <bits/stdc++.h>
#define in(n, arr) for (int i = 0; i < n; ++i) cin >> arr[i]
#define out(n, arr) for (int i = 0; i < n; ++i) cout << arr[i] << " "
 
using namespace std;
long long int solve(long long int** dp, long long int* arr, long long int l, long long int r)
{
	if(l > r)
		return  0;
	if(l == r)
		return arr[l];
	if(dp[l][r]!=-1)
		return dp[l][r];
	long long int ans = arr[l] - solve(dp,arr,l+1,r);
	ans = max(ans,arr[r]-solve(dp,arr,l,r-1));
	dp[l][r] = ans;
	return ans;

}
int main()
{
	
	int t;
	cin >> t;
	long long int* arr = new long long int[t]();
	for(int  i =0; i<t; i++)
		cin >> arr[i];
	long long int** dp = new long long int*[t];
	for(int  i = 0; i<t; i++)
		dp[i] = new long long int[t];
	for(int i =0; i<t; i++)
	{
		for(int  j = 0; j<t; j++)
			dp[i][j] = -1;
	}
	cout << solve(dp, arr, 0, t-1) << endl;



return 0;
}