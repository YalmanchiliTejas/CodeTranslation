#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int arr[3005];
int dp[3005][3005];
int jiro;
int solve(int i,int j){

if(i>j)
return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];

	int op1 = arr[i] + min(solve(i+2,j),solve(i+1,j-1));	
	int op2 = arr[j] + min(solve(i+1,j-1),solve(i,j-2));

	int ans = max(op1,op2);
	if(ans == op1)
		jiro = solve(i+1,j);
	else 
		jiro = solve(i,j-1);

return dp[i][j] = ans;

}

int32_t main(){
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	jiro = 0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=-1;

	cout<<solve(1,n)-jiro<<endl;
	//cout<<jiro<<endl;


}