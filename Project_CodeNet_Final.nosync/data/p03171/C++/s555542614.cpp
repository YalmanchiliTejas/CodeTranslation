#include<iostream>
#define ll long long int
using namespace std;
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	
	ll x[n][n],y[n][n];
	
	int i=0;
	while(i<n)
	{
		x[i][i]=a[i];
		y[i][i]=0;
		i++;
	}
	
	for(int k=1;k<n;k++)
	{
		
		int i=0,j=k;
		while(i<n&&j<n)
		{
			ll q=a[i]+y[i+1][j];
			ll w=a[j]+y[i][j-1];
			
			if(q>=w)
			{
				x[i][j]=q;
				y[i][j]=x[i+1][j];
			}
			else
			{
				x[i][j]=w;
				y[i][j]=x[i][j-1];
			}
			i++;j++;
		}
		
	}
	
//    for(int i=0;i<n;i++)
//    {
//    	for(int j=0;j<n;j++)
//    	{
//    		cout<<x[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<"*******************"<<endl;
//	 for(int i=0;i<n;i++)
//    {
//    	for(int j=0;j<n;j++)
//    	{
//    		cout<<y[i][j]<<" ";
//		}
//		cout<<endl;
//	}

cout<<x[0][n-1]-y[0][n-1];
}