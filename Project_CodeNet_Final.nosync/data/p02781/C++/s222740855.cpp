
#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;

string s;
ll k;
ll n;

ll dp[105][105][2];

ll solve(ll id,ll num,ll flg)
{
	//cout<<id<<" "<<num<<" "<<flg<<endl;
	if(id==n)
	{
		if(num==k)return 1;
		return 0;
	}
	
	if(dp[id][num][flg]==-1)
	{
		ll cur = 0;
		ll ed = s[id]-'0';
		if(flg)ed=9;
		for(ll i=0;i<=ed;i++)
		{
			
				if(flg)
				{
					if(i==0)
						cur += solve(id+1,num,flg);
					else
						cur += solve(id+1,num+1,flg);
				}
				else
				{
					if(i==ed)
					{
						if(i==0)
							cur += solve(id+1,num,flg);
						else
							cur += solve(id+1,num+1,flg);
					}
					else
					{	
						if(i==0)
							cur += solve(id+1,num,1);
						else
							cur += solve(id+1,num+1,1);
					}
				}
			
		}
		
		dp[id][num][flg] = cur;
		
	}
	return dp[id][num][flg];
	
}

int main()
{
    std::ios_base::sync_with_stdio(0);	
    cin.tie(0);
    cout.tie(0);
    
    cin>>s>>k;
   // cout<<s<<" "<<k<<endl;
    n = s.size();
   //  cout<<n<<endl;
    memset(dp,-1,sizeof(dp));
    
    cout<<solve(0,0,0);
    
    
}
