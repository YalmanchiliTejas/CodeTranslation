#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
ll mod = 1e9+7;
ll INF = 1e17;
/*ll gcd(ll a,ll b)
{
    if(a==0)
    return(b);
    return(gcd(b%a,a));
}*/
/*ll power(ll a,ll b,ll p)
{
	ll res=1;
	a%=p;
	while(b>0)
	{
		if(b&1)
		res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return(res);
}*/
/*void dfs(ll x)
{
	vis[x]=true;
	for(ll i=0;i<v[x].size();i++)
	{
		if(vis[v[x][i]]==false)
		dfs(v[x][i]);
	}
}*/
/*ll b_search(ll arr[],ll n,ll s)
{
	ll l=0,r=n-1;
	while(l<=r)
	{
		ll mid=l+(r-l)/2;
		if(arr[mid]==s)
		return(mid);
		if(arr[mid]<s)
		l=mid+1;
		else
		r=mid-1;
	}
	return(-1);
}*/
 
void solve()
{
	ll n,m;
	cin>>n>>m;
	if(n==m)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}
 
int main()
{
	IOS
	ll t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
    return(0);
}
