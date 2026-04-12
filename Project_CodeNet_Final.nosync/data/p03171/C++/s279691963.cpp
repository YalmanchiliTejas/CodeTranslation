#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define mp make_pair
#define S second
#define F first
ll mod=1e9+7;
#define input_from_file  freopen("input.txt", "r", stdin);

int main()
{
  // input_from_file;
  ll n,w=0,x=0,y=0,z=0,sum=0;
  cin>>n;vector<ll> vec(n,0);
      for(int i=0;i<n;i++)    {cin>>vec[i];sum+=vec[i];}
	    // if(n==1)    {cout<<vec[0];return 0;}
	    // if(n==2)    {cout<<max(vec[0],vec[1])-min(vec[0],vec[1]);return 0;}
	    
	    vector<vector<ll>> dp(n,vector<ll> (n,0));
	    for(int i=0;i<n;i++)    dp[i][i]=vec[i];
	    for(int i=0;i<n-1;i++)    dp[i][i+1]=max(vec[i],vec[i+1]);
	    for(int gap=2;gap<n;gap++){
	        for(int i=0;i<n-gap;i++){
	            w=dp[i+2][i+gap];
	            x=dp[i+1][i+gap-1];
	            z=dp[i][i+gap-2];
	            dp[i][i+gap]=max(vec[i]+min(x,w),vec[i+gap]+min(x,z));
	        }
	    }
	    cout<<2*dp[0][n-1]-sum<<endl;
  return 0;
}
