#include<iostream>
#include<cstdio>
using namespace std;
#define PI 3.1415927
int main()
{
	int i,max=0,n,ans=0,x;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x>=max)
		{
			max = x;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}