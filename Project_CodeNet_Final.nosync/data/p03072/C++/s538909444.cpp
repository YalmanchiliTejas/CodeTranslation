#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,mx,ans,i,h;
	scanf("%d",&n);
	mx=0;ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h);
		if(h>=mx)ans++;
		mx=max(mx,h);
	}
	printf("%d",ans);
	return 0;
}