 
//BELIEVE IN YOURSELF
//next_permutation

#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define pob pop_back
#define vi vector<ll>
#define mp make_pair
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define maxx 100005
#define se second
#define fi first
#define be begin()
#define en end()
#define sortv(v) sort(v.begin(),v.end());
#define w() ll _;cin>>_;while(_--)
#define edge pair<ll,ll>
#define pq priority_queue<ll>
#define mod 1000000007
#define Endl "\n"
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define lb(v,x) std::lower_bound(v.begin(),v.end(),x)
#define ub(v,x) std::upper_bound(v.begin(),v.end(),x)

using namespace std;


     
int main()
{
	fast;
		
	ll n;
	
	ll i;
	cin>>n;
	ll a[n+1];
	
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]%=mod;
	}
	ll pre[n+1]={0};
	pre[0]=a[0];
	ll sum=a[0];
	for(i=1;i<n;i++)
	{
		sum+=a[i];
		sum%=mod;
		pre[i]=(a[i]+pre[i-1])%mod;
	}
	ll ans=0;
	for(i=0;i<n;i++)
	{
		ans=(ans%mod + (a[i]*(mod+sum-pre[i]))%mod )%mod;
	}
	
	
	cout<<ans<<endl;
	
	return 0;
}
     
     
     
     
     
     
     
     
     
     
     
     