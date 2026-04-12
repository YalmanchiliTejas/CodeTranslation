#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e11+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=3005;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound

ll dp[105][10][2];
ll solve(string s,int k,int pos,int st)
{
	if(pos==s.length()&&k>0||k<0)
		return 0;
	if(pos==s.length()&&k==0)
		return 1;
	if(dp[pos][k][st]!=-1)
		return dp[pos][k][st];
	ll ans=0;
	int limit=s[pos]-'0';
	if(st==0)
		limit=9;
	int i;

   
    	for(i=0;i<=limit;i++)
    	{
    		int str=st;
              if(i<limit)
              	str=0;
    		if(i>0)
    		{  
    			if(k>0)
                ans+=solve(s,k-1,pos+1,str);
            else
            	continue;

    		}
    		 if(i==0)
    		{
    			ans+=solve(s,k,pos+1,str);
    		}
    	}
    
    	dp[pos][k][st]=ans;
    	return ans;
    
}
int main()
{
     int k;
     string s;
     cin>>s>>k;
     //cout<<s;
     memset(dp,-1,sizeof(dp));
     cout<<solve(s,k,0,1)<<"\n";
}