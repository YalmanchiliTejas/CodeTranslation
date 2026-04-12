#include<iostream>
using namespace std;
long N,X,M;
int vis[1<<17];
long pre[1<<17];
main()
{
	cin>>N>>X>>M;
	for(int i=0;i<M;i++)vis[i]=-1;
	long ans=0;
	int tu=0;
	while(N>0)
	{
		if(vis[X]>=0)
		{
			int be=tu-vis[X];
			ans+=(ans-pre[X])*(N/be);
			N%=be;
		}
		if(N>0)
		{
			vis[X]=tu++;
			pre[X]=ans;
			ans+=X;
			N--;
			X=X*X%M;
		}
	}
	cout<<ans<<endl;
}
