//Code by Mukul Totla
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sublime(){ 
	#ifndef ONLINE_JUDGE 
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
      }
	ll mod=1e9+7;
int main()
{   
     //sublime();
	  ll n,i;
	   cin>>n;
	   ll arr[n];
	   ll sum=0;
	   for(i=0; i<n; i++)
	    {
	    	cin>>arr[i];
	    	sum+=arr[i];
	    	sum%=mod;
	    }
	    ll psum[n];
	    memset(psum,0,sizeof(psum));
	    
	    for(i=0; i<n; i++)
	    {
           sum-=arr[i];
           sum=(sum+mod)%mod;
           psum[i]=sum;
	    } 
	    
	    ll ans=0;
	    for(i=0; i<n-1; i++)
	    {
	    	ans+=(arr[i]*psum[i])%mod;
	    	ans%=mod;
	    }
	    cout<<ans;
	    
	   
	return 0;
}
