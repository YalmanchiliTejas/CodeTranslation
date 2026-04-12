#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[55],Patty[55];
int Solve(int Level,int Layer)
{
	if(Layer==0) return 0;
	if(Level==0) return 1;
	if(Layer==1) return 0;
	if(Layer==dp[Level-1]+1) return Patty[Level-1];
	if(Layer==dp[Level-1]+2) return Patty[Level-1]+1;
	if(Layer==dp[Level]-1) return Patty[Level];
	if(Layer==dp[Level]) return Patty[Level];
	if(Layer<dp[Level-1]+1) return Solve(Level-1,Layer-1);
	return Patty[Level-1]+1+Solve(Level-1,Layer-2-dp[Level-1]);
}
signed main()
{
	int N,X;
	cin>>N>>X;
	dp[0]=1,Patty[0]=1;
	for(int i=1;i<=N;i++) dp[i]=dp[i-1]*2+3,Patty[i]=(dp[i]+1)/2;
	cout<<Solve(N,X)<<endl;
	return 0;
}