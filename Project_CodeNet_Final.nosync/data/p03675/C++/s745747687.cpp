#include <iostream>
#include <algorithm>
using namespace std;
int a[200010],n;
int main()
{
	cin>>n;int i,x,y;
	x=n-1;y=0;
	for(i=0;i<n;i++)
	cin>>a[i];
	if(n%2==0)
	{
		while(x>=0)
		{
		cout<<a[x]<<" ";
	    x-=2;
	}
	while(y<n)
	{
		cout<<a[y]<<" ";
		y+=2;
	}
	}
	else
	{
		x=n-1;y=1;
		while(x>=0)
		{
			cout<<a[x]<<" ";
			x-=2;
		}
		while(y<n)
		{
			cout<<a[y]<<" ";
			y+=2;
		}
	}
	return 0;
}