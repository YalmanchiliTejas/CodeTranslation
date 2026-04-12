#include<bits/stdc++.h>
#define int long long 
using namespace std;

int dp[3001][3001];

int solve(int a[],int i, int j){
	if (i==j){
		dp[i][j] = a[i];
		return a[i];
	}
	if  (dp[i][j]!=1e15){
		return dp[i][j];
	}
	dp[i][j] = max(a[i]-solve(a,i+1,j),a[j]-solve(a,i,j-1));
	return dp[i][j];
}

signed main(){

	//freopen("input.txt","r",stdin);
	int n;
	cin >> n;
	int a[10000];
	for (int i=0; i<3001;  i++){
		for (int j=0; j<3001;  j++){
			dp[i][j] = 1e15;
		}
	}
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	cout << solve(a,0,n-1);
 	cout << endl;
}