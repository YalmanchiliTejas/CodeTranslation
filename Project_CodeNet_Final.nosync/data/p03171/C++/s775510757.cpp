#include <bits/stdc++.h>

using namespace std;

long long int dp[3005][3005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0 ; i < n ; i++)
		cin >> a[i];
 	for (int L = n ; L >= 0 ; L--)
 	{
 		for (int R = L ; R < n ; R++)
 		{
 			if (L == R)
 				dp[L][R] = a[L];
 			else
 				dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);			
 		}		
 	}
	cout << dp[0][n-1] << "\n" ;
	return 0;
}

/*
 	My thoughts and explained for this problem:
 	There is an O(n) solution for this problem in Looking for a challenge problem Termites
    Example for the test case:
    3
    10 80 90
	Answer will be dp[0][2]
	dp[0][2] = max (10 - dp[1][2], 90 - dp[0][1])
	dp[1][2] = max (80 - dp[2][2], 90 - dp[1][1])
	dp[0][1] = max (10 - dp[1][1], 80 - dp[0][0])
	=> dp[0][1] and dp[1][2] must be calculated first => We should loop backward 
 */