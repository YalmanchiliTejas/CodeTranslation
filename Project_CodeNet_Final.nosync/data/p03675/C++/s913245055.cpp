#include<cstdio>
#include<iostream>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N],b[N],tot;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n&1)
	{
		for(int i=n;i>=1;i-=2)
			b[++tot]=a[i];
		for(int i=2;i<=n-1;i+=2)
			b[++tot]=a[i];
	}
	else
	{
		for(int i=n;i>=2;i-=2)
			b[++tot]=a[i];
		for(int i=1;i<=n-1;i+=2)
			b[++tot]=a[i];
	}
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
}