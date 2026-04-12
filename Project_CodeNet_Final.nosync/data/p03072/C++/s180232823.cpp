#include<bits/stdc++.h>
using namespace std;
int main()
{
	int maxx=-1,n,ans=1;
	scanf("%d%d",&n,&maxx);
	for(int i=1,x;i<n;i++)
	{
		scanf("%d",&x);
		if(x>=maxx)ans++,maxx=x;
	}
	printf("%d",ans);
	return 0;
}
