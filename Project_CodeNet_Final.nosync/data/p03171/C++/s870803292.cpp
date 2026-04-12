#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
ll dp[3000+5][3000+5][2];
ll arr[3000+5];

/* (i, j) -> max(A[i]+(i+1, j), A[j]+(i,j-1))
solve(i, j, c) -> c*max(arr[i] + solve(i+1, j, 1-c), arr[j] + solve(i, j-1, 1-c)) +
			(1-c)*min(arr[i] + solve(i+1, j, 1-c), arr[j] + solve(i, j-1, 1-c));
				
ll solve(ll i, ll j, ll c, ll X, ll Y){
	if (i > j) return X-Y;
	
	//if(dp[i][j][c] != -1) return dp[i][j][c];
	
	ll ans;
	if (c)
		ans = max(solve(i+1, j, 1-c, X+arr[i], Y), solve(i, j-1, 1-c, X+arr[j], Y));
	else
		ans = min(solve(i+1, j, 1-c, X, Y+arr[i]), solve(i, j-1, 1-c, X, Y+arr[j]));
	return ans;
}*/

ll solve(ll i, ll j, ll c){
	if (i > j) return 0;
	
	if(dp[i][j][c] != -1) return dp[i][j][c];
	if (c)
		dp[i][j][c] = max(arr[i]+solve(i+1, j, 1-c), arr[j]+solve(i, j-1, 1-c));
	else
		dp[i][j][c] = min(solve(i+1, j, 1-c)-arr[i], solve(i, j-1, 1-c)-arr[j]);
	return dp[i][j][c];
}
			

int main(){
	cin>>N;
	for(ll i = 0;i<N;i++)cin>>arr[i];
	
	memset(dp, -1, sizeof dp);
	
	cout<<solve(0,N-1, 1)<<endl;
}	