#include<bits/stdc++.h>
using namespace std;

long long int n;
vector<long long int> v;
long long int mem[3005][3005][3];
	
long long int dp(long long int i,long long int j,long long int t){
	if(i==j){
		if(t==0)
		return v[i];
		else
		return (-1)*v[i];
	}
	if(mem[i][j][t]!=-1)
	return mem[i][j][t];
	long long int ans;
	if(t==0){
		ans = dp(i+1,j,1-t)+v[i];
		ans = max(ans,v[j]+dp(i,j-1,1-t));
	}
	if(t==1){
		ans = dp(i+1,j,1-t)-v[i];
		ans = min(ans,dp(i,j-1,1-t)-v[j]);
	}
	mem[i][j][t]=ans;
	return ans;
}
	
int main(){
	
	cin>>n;
	memset(mem,-1,sizeof(mem));
	for(long long int i=0;i<n;i++)
	{
		long long int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<dp(0,n-1,0);
	return 0;
}