#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,a[N];

int main()
{
	int mx=0,i,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]>=mx) mx=a[i],++ans;
	}
	printf("%d\n",ans);
	return 0;
}