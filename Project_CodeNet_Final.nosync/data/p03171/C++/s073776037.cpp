#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll arr[n],i,j,k,x,y;
	for(i=0;i<n;i++)
		cin>>arr[i];
	pair<ll,ll> mat[n][n];
	for(i=0;i<n;i++)
	{
		j=0;
		k=i;
		while(j<n && k<n)
		{
			if(j==k)
			{
				mat[j][k].first=arr[j];
				mat[j][k].second=0;
			}
			else
			{
				x=arr[j]+mat[j+1][k].second;
				y=arr[k]+mat[j][k-1].second;
				if(x>y)
				{
					mat[j][k].first=x;
					mat[j][k].second=mat[j+1][k].first;
				}
				else
				{
					mat[j][k].first=y;
					mat[j][k].second=mat[j][k-1].first;
				}
			}
			j++;
			k++;
		}
	}
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<mat[i][j].first<<" "<<mat[i][j].second<<"   ";
		cout<<endl;
	}*/
	cout<<mat[0][n-1].first-mat[0][n-1].second<<endl;
	return 0;
}