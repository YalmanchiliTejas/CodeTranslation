#include <bits/stdc++.h>
using namespace std;
long long n, arr[3001], dp[3001][3001], ans, dif, sum=0;
bool vis[3001][3001];

long long solve(long long i, long long j){
	if(vis[i][j]){
		return dp[i][j];
	}
	if(i==j){
		return dp[i][j]=arr[i];
	}
	if(i>j){
		return dp[i][j]=0;
	}
	vis[i][j]=1;
	long long d=arr[i]+min(solve(i+2, j), solve(i+1, j-1));
	long long b=arr[j]+min(solve(i, j-2), solve(i+1, j-1));
	return dp[i][j]=max(d, b);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sum+=arr[i];
	}
	long long x, y;
	x=solve(0, n-1);
	y=sum-x;
	cout << x-y << endl;

}