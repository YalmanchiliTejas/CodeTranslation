#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int arr[3001],n;
long long dp[3001][3001];
long long f(int i,int j){
	if(i>j)return 0;
	long long &res=dp[i][j];
	if(~res)return res;
	if(!((n-j+i-1)&1)){
		return res=max(f(i+1,j)+arr[i],f(i,j-1)+arr[j]);
	}else{
		return res=min(f(i+1,j)-arr[i],f(i,j-1)-arr[j]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof dp);
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	cout<<f(0,n-1)<<endl;
	return 0;
}