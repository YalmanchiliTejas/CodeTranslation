#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll a[3000];
ll dp[3000][3000];

ll optimal(ll i,ll j){
	if(i>j)
	return 0;
	
	if(dp[i][j]!=-1)
	return dp[i][j];
	
	ll op1=a[i]+min(optimal(i+2,j),optimal(i+1,j-1));
	ll op2=a[j]+min(optimal(i,j-2),optimal(i+1,j-1));
	return dp[i][j]=max(op1,op2);
}

int main(){
	cin>>n;
	ll sum=0;
	for(ll i=0;i<n;i++)
	cin>>a[i],sum+=a[i];
	memset(dp,-1,sizeof(dp));
	ll maxv=optimal(0,n-1);
	ll other=sum-maxv;
	cout<<maxv-other<<endl;
	
}