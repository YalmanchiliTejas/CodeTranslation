#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[3001][3001][2];
int solve(vector<int>& vec, int i, int j, int turn)
{
	if(i > j)return 0;
	if(dp[i][j][turn] != -1)return dp[i][j][turn];
	if(turn == 1){
		return dp[i][j][turn] = max(vec[i] + solve(vec, i + 1,j,0) , vec[j] + solve(vec, i, j-1, 0));
	}
	else{
		return dp[i][j][turn] = min(solve(vec, i + 1,j,1) , solve(vec, i, j-1, 1));
	}
}
signed main()
{
	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	vector<int> vec(n + 1);
	int sum = 0;
	for(int i = 1; i<= n; i++){
		cin >> vec[i];
		sum += vec[i];
	}
	int sum_x =  solve(vec, 1, n, 1);
	int sum_y = sum - sum_x;
	cout << sum_x - sum_y;
}