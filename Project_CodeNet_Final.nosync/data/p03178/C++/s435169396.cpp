#include <bits/stdc++.h>
using namespace std;
string arr;
int d;
int mod=1e9+7;
long long getsum(int ind,int sum,int flag,vector<vector<vector<long long> > >&dp){
	if(ind==arr.size()) {
		if(sum%d==0) return 1;
		return 0;
	}
	if(dp[ind][sum][flag]!=-1) return dp[ind][sum][flag];
	int limit=9;
	if(!flag) limit=arr[ind]-'0';
	long long res=0;
	for(int i=0;i<=limit;i++){
		if(flag||i<limit){
			res+=getsum(ind+1,(sum+i)%d,1,dp);
		}
		else res+=getsum(ind+1,(sum+i)%d,0,dp);
	}
	dp[ind][sum][flag]=res%mod;
	return res%mod;
	
	
}
int main() {
	
		
		cin>>arr;
	    cin>>d;
	
		
		
		
			vector<vector<vector<long long> > >dp(arr.size()+1,vector<vector<long long> >(200,vector<long long>(2,-1)));
		long long u=getsum(0,0,0,dp);
		
		
		cout<<(u-1+mod)%mod<<endl;
		
		
	
	
	return 0;
}