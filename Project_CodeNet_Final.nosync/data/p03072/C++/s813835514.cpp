#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ok=0,c=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]<a[j])
			{
				ok=1;
				break;
			}
		}
		if(ok==0)
		{
			c++;
		}
		else
		{
			ok=0;
		}
	}
	cout<<c<<endl;
	return 0;
}