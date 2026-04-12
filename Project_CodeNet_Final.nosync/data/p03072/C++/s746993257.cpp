#include<bits/stdc++.h>
using namespace std; 
#define ll long long int
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define INF LLONG_MAX
#define PI acos(-1)
#define MOD 1e9 + 7
#define N 1e5 + 10
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll i=0,c=0,count=0,j=0;
	ll h[n];
	for(i=0;i<n;i++)
	{
		cin>>h[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(h[i]>=h[j])
			{
				count++;
			}
		}
		if(count==i)
		{
			//cout<<h[i]<<" ";
			c++;
		}
		count=0;
	}	
	cout<<c;
}	