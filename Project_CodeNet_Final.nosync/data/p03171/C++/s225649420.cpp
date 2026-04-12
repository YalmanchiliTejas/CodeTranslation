// author:-*mdragneell*

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pi  pair<int,int>
#define pl  pair<ll,ll>

int const N=3001;
ll min(ll x,ll y) { if(x<y) return x; else return y; }
ll max(ll x,ll y) { if(x>y) return x; else return y; }

ll cache[N][N][2];
ll n,m,a[N];

ll sol(ll i,ll j,ll player)
{
		if(i>j) return 0;
		if(cache[i][j][player]!=-1)
			return cache[i][j][player];

		if(player==0)
			return cache[i][j][player]=max(a[i]+sol(i+1,j,player^1),a[j]+sol(i,j-1,player^1));
		else
			return cache[i][j][player]=min(-a[i]+sol(i+1,j,player^1),-a[j]+sol(i,j-1,player^1));

}

int main()
{
		ll i,j;
		cin>>n;

		memset(cache,-1,sizeof(cache));

		for(i=0;i<n;i++)
				cin>>a[i];
		cout<<sol(0,n-1,0)<<endl;

}
