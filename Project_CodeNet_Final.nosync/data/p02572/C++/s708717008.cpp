#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
#define rep(i,n) for(int i=0;i<n;i++) 
#define all(v) v.begin(),v.end()
#define F first
#define S second 
const ll MOD=1e9+7;
template<typename ForwardIterator,typename T>
ForwardIterator first_less_than(ForwardIterator first,ForwardIterator last,T val)
{
	auto it=lower_bound(first,last,val);
	return (it==first?first:it);
}

void solve()
{
	ll n;
	cin>>n;
	ll arr[n];
	rep(i,n)
	{
		cin>>arr[i];
	}
	ll res[n];
	res[n-1]=arr[n-1]%MOD;
	for(int i=n-2;i>=0;i--)
	{
		res[i]=(res[i+1]+arr[i])%MOD;
	}
	ll sum=0;
	for(int i=0;i<n-1;i++)
	{
		sum+=((arr[i]%MOD)*(res[i+1])%MOD)%MOD;
	}
	cout<<sum%MOD<<endl;
	
}

int main()
{
	ios_base::sync_with_stdio(false); 
  	 cin.tie(NULL);  
	int tt;
	tt=1;
	while(tt--)
	{
		solve();
	}
}
