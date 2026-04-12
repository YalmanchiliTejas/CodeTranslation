#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
#define minf -10000000000000000
ll a[N];
ll ans=0;
ll n;
map<pair<ll,ll>,ll>mp,ex;

ll cal(ll taken,ll i)
{
	if(i>n-1)
	{
		if(taken==n/2)
		  return 0;
		else
		  return minf;
	}
	if(taken==n/2)
	  return 0;
	
	if((n-i+1)/2+taken<n/2)
	{
		  return minf;
	}
	
	if(ex[{i,taken}]==1)
	  return mp[{i,taken}]; 
	ll ans;
	ans=max(cal(taken,i+1),a[i]+cal(taken+1,i+2));
	mp[{i,taken}]=ans;
	ex[{i,taken}]=1;
	return ans;		
}


int main()
{

	cin>>n;
	for(int i=0;i<n;i++)
	  cin>>a[i];
	
	  
	  
    cout<<cal(0ll,0ll)<<endl;	
//    for(auto it:mp)
//	{
//	    cout<<"key "<<it.first.first<<" "<<it.first.second<<endl;
//	    cout<<"value ";
//		for(auto it1:it.second)
//		  cout<<it1<<" ";
//		  cout<<endl;	
//	}  
}