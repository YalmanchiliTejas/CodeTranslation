#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
#define int ll
#define pb push_back
const int INF = 1e18, MAX = 3003;

int n, arr[MAX];
vector<vector<int>> dp;

int solve(int left, int right){
	if (left==right){
		if (n&1)
			return dp[left][right] = arr[left];
		else
			return dp[left][right] = -arr[left];
	}

	if (dp[left][right] != INF)
		return dp[left][right];

	if (((left+right)&1) != (n&1))
		return dp[left][right] = max(arr[left] + solve(left+1,right), arr[right] + solve(left,right-1));
	else
		return dp[left][right] = min(-arr[left] + solve(left+1,right), -arr[right] + solve(left,right-1));
}
signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	dp.assign(n+1,vector<int> (n+1, INF));
	cout<<solve(1,n)<<"\n";


	

	return 0;
}