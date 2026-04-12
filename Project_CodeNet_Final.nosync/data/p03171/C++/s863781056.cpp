#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	ll sum=0;
	for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}

	ll table[n+1][n+1];

	for(ll k=0;k<n;k++)
	{
		for(ll i=0,j=k;j<n;i++,j++)
		{
			if(k==0)
			{
				table[i][j]=arr[i];
			}
			else
			if(k==1)
			{
				table[i][j]=max(arr[i],arr[j]);
			}
			else
			{
				ll x=((i+2)<=j)?table[i+2][j]:0;
				ll y=((i+1)<=(j-1))?table[i+1][j-1]:0;
				ll z=(i<=(j-2))?table[i][j-2]:0;

				table[i][j]=max(arr[i]+min(x,y),arr[j]+min(y,z));
			}
		}
	}

	cout<<(2*table[0][n-1]-sum)<<endl;
	return 0;
}