#include<bits/stdc++.h>

using namespace std;

int const size = 3006;
int arr[size];
long long int dp[2][size][size];

long long int solve(int turn, int left, int right){
	if(left>right) return 0;
	if(dp[turn][left][right] != -1) return dp[turn][left][right];
	long long int ans = 0;
	if(turn == 0){
		ans = max(arr[left] + solve(1, left+1, right), arr[right]+solve(1, left, right-1));
	} else ans = min(solve(0, left+1, right) - arr[left], solve(0, left, right-1)- arr[right]);
	dp[turn][left][right] = ans;
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int x=0;x<n;x++) scanf("%d",&arr[x]);
	for(int x=0;x<size;x++){
		for(int i=0;i<size;i++) for(int j=0;j<2;j++) dp[j][x][i] = -1;
	}
	cout<<solve(0,0,n-1);
	return 0;
}