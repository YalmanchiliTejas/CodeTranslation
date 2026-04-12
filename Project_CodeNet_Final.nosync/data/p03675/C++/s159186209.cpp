#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

int n,x;
int a[N];


int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		int y=(n-i)/2;
		if((n-i)&1)
			a[n-y]=x;
		else a[y+1]=x;
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
}