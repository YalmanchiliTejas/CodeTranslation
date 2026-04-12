#include<bits/stdc++.h>

using namespace std;

const int size = 3005;
int arr[size];
long long int dp[2][size][size];

long long int check(int l, int r, int c){
	if(l == r){
		if(c == 0)
		return arr[l];
		else return -arr[l];
	}
	if(dp[c][l][r] != -1) return dp[c][l][r];

	if(c == 0) dp[c][l][r] = max(arr[l] + check(l+1,r, 1), arr[r] + check(l, r-1, 1));
	else dp[1][l][r] = min(check(l+1, r, 0) - arr[l], check(l,r-1,0) - arr[r]);

	// cout<<c<<" "<<l<<" "<<r<<" "<<dp[c][l][r]<<"\n";

	return dp[c][l][r];
}

int main(){
	int n;
	cin>>n;

	for(int x=0;x<n;x++) cin>>arr[x];
	int l=0, r = n-1;
	for(int x=0;x<n;x++) for (int i=0;i<n;i++) dp[0][i][x] = dp[1][i][x] = -1;
	cout<<check(l, r, 0);
	return 0;
}