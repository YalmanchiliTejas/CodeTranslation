#include<iostream>
#include<algorithm>
using namespace std;
int N,S[1<<17],vis[1<<17];
long ans;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>S[i];
	for(int i=1;i<N;i++)
	{
		long now=0;
		int L=0,R=N-1;
		while(R>i+i)
		{
			L+=i;R-=i;vis[L]=i;
			if(vis[R]<i)ans=max(ans,now+=S[L]+S[R]);
			else break;
		}
	}
	cout<<ans<<endl;
}