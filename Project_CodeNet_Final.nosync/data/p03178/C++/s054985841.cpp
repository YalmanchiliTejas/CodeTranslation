#include <bits/stdc++.h> 
  
#define ll long long 
  
using namespace std; 
  
vector<ll> v; 
  
ll dp[10005][105][2],d,mod=1000000007; 

ll solve(ll n,ll sum,ll flag)
{
	if(n==v.size())
	{
		if(sum==0)
			return 1;
		else return 0;
	}
	if(dp[n][sum][flag]!=-1)
		return dp[n][sum][flag]%mod;
	
	 ll x=0,en=-1;
	 
	 if(flag==1)
		 en=v[n];
	 else
		 en=9;
	
	 for(ll i=0;i<en;i++)
		 x=(x%mod+solve(n+1,((sum%d)+i)%d,0)%mod)%mod;
	 x=(x%mod+solve(n+1,((sum%d)+en)%d,flag)%mod)%mod;
	return (dp[n][sum][flag]=x);
}


ll CountNum(string n) 
{ 
    v.clear();
    int sz=n.length();
	for(int i=0;i<sz;i++)
		v.push_back(n[i]-'0');    
      
    memset(dp, -1, sizeof(dp)); 
    return solve(0, 0, 1); 
} 
    
int main() 
{ 
    string k; 	
	cin>>k>>d;
	ll ans=CountNum(k)-1;
	if(ans==-1)
		ans=mod-1;
    cout << ans << endl; 
    return 0; 
} 