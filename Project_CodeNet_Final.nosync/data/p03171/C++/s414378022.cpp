#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> a(3000, 0);
long long tmp[3005][2] = {-1};
vector<vector<vector<long long> > > dp(3000, vector<vector<long long>>(3000, vector<long long>(2, -1)));

long long helper(int i, int j, int c){
	if(i > j)
		return 0;
	if(dp[i][j][c] != -1)
		return dp[i][j][c];
	if(c == 1)
		return dp[i][j][c] = max(a[i] + helper(i+1, j, 0), a[j] + helper(i, j-1, 0));
	else
		return dp[i][j][c] = min(helper(i+1, j, 1), helper(i, j-1, 1));
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	// vector<bool> dp(k+1, false);
	long long total = 0;	
	for(int i=0; i<n; i++){
		cin>>a[i];
		total += a[i];
	}
	// dp[0] = false;
	
	// for(int i=0; i<3000; i++)
	// 	for(int j=0; j<3000; j++)
	// 		for(int z=0; z<2; z++)
	// 			cout<<dp[i][j][z]<<' ';
	long long res = helper(0, n-1, 1);
	// cout<<res<<endl;
	// cout<<total<<endl;
	cout<<2*res - total;
	// while(i <= j){
	// 	if(a[i] > a[j]){
	// 		if(c == 0)
	// 			x += a[i];
	// 		i++;
	// 	}
	// 	else if()
	// }
	// for(int i=0; i<n; i++) cin>>choices[i];
	
	return 0;
}