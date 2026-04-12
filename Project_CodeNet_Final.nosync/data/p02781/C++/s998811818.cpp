#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int mod = 1e9+7;
ull getsum(long long n,ull sum,int flag,int ind, string &a,vector<vector<vector<ull>>>&dp,int k)
{
    
	if(ind>n)
	{
		if(sum==k)return 1;
		return 0;
	}

	int limit=9;
	
	if(!flag)limit = a[ind]-'0';
	
	if(dp[ind][sum][flag]!=-1)return dp[ind][sum][flag];
	ull res=0;
	
	for(int i=0;i<=limit;i++)
	{   
		
		if(flag || i<limit)
		{
			res+=getsum(n,sum+!(!i),true,ind+1,a,dp,k);
		}
		
		else
		{
			res+=getsum(n,sum+!(!i),false,ind+1,a,dp,k);
		}
	}
	
	return dp[ind][sum][flag]=res;
}
int main() {
	// your code goes here
	
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	int k;
	
    cin>>a>>k;
 
    int n = a.size();
  
	vector<vector<vector<ull>>>dp(101,vector<vector<ull>>(101,vector<ull>(2,-1)));
	ull res1 = getsum(n-1,0,0,0,a,dp,k);

	cout<<res1<<endl;
		
	return 0;
}