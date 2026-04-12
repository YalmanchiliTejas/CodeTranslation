#include<bits/stdc++.h>
using namespace std;
#define md 1000000007
#define ll long long 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fastmap mp.reserve(1024);mp.max_load_factor(0.25);
#define fastset st.reserve(1024);st.max_load_factor(0.25);
ll int mpw(ll int a,ll int b,ll int m)
{
	ll int ans=1;
	if(a==0)return 0;
	if(a==1 || b==0)return 1;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%m;
		}
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}
 
ll int pw(ll int a,ll int b)
{
	ll int ans=1;
	if(a==0)return 0;
	if(a==1 || b==0)return 1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
		}
		a*=a;
		b>>=1;
	}
	return ans;
}
 
ll int mn(ll int a,ll int b)
{
	if(a<=b)
	{
		return a;
	}
	return b;
}
 
ll int mx(ll int a,ll int b)
{
	if(a>=b)
	{
		return a;
	}
	return b;
}
 
int main()
{
	fio
	int n;
	cin>>n;
	vector<ll int>nm(n);
	for(int i=0;i<n;++i)
	{
		cin>>nm[i];
	}
	vector<vector<pair<ll int,ll int>>>D(n,vector<pair<ll int,ll int>>(n,{0,0}));
	for(int i=0;i<n;++i)
	{
		for(int j=i;j>=0;--j)
		{	
			if(i==j)
			{
				D[j][i]={nm[i],0};
			}
			else{
				if(nm[j]+D[j+1][i].second>=nm[i]+D[j][i-1].second)
				{
					D[j][i]={nm[j]+D[j+1][i].second,D[j+1][i].first};
				}
				else{
					D[j][i]={nm[i]+D[j][i-1].second,D[j][i-1].first};
				}
			}
		}
	}
	cout<<D[0][n-1].first-D[0][n-1].second<<"\n";
	return 0;
}