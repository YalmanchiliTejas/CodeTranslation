#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long int dp[3001][3001];
long long int min(long long int a,long long int b)
{
    if(a>b) return b;
    return a;
}
long long int max(long long int a,long long int b)
{
    if(a>b) return a;
    return b;
}
long long int util(vector<long long int>&v,int i,int j)
{
    if(i==j) return v[i];
    if(i+1==j) return max(v[i],v[j]);
    if(dp[i][j]!=-1) return dp[i][j];
    long long int ma = max(v[i]+min(util(v,i+1,j-1),util(v,i+2,j)),v[j]+min(util(v,i,j-2),util(v,i+1,j-1)));
    dp[i][j]=ma;
    return ma;
}
int main() {
	int n;
	cin>>n;
	vector<long long int>v(n);
	memset(dp,-1,sizeof(dp));
	long long int tot=0;
	for(int i=0;i<n;i++)
	{
	    cin>>v[i];
	    tot+=v[i];
	}
	long long int ret = util(v,0,n-1);
	cout<<(2*1LL*ret-tot)<<endl;
	return 0;
}