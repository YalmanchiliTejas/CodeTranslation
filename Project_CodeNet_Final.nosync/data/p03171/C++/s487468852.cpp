#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ld long double
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rloop(i,a,b) for(ll i=a;i>b;i--)
const int inf=1e9+7;



int main()
{

ll n;
cin>>n;

ll a[n];
	loop(i,0,n)cin>>a[i];
	
	ll dp[n][n];
	rloop(l,n-1,-1)
	{
		loop(r,l,n)
		{
			if(r==l)dp[l][r]=a[l];
			else
			{
				dp[l][r]=max(a[r]-dp[l][r-1],a[l]-dp[l+1][r]);
			}
			
		
			
		}
	
	}
	
	cout<<dp[0][n-1];
	
	
}
