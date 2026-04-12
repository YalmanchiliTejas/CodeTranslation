#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int q,x,M,i,vis[N],j;
long long s[N],n,ans;
int main()
{
	scanf("%lld %d %d",&n,&x,&M);
	s[1]=x;
	vis[x]=1;
	for(i=2;i<=n;++i)
	{
		s[i]=s[i-1]*s[i-1]%M;
		if(vis[s[i]])
			break;
		vis[s[i]]=i;
	}
	if(i>n)
	{
		for(i=1;i<=n;++i)
			ans+=s[i];
		cout<<ans;
	}
	else
	{
		for(j=1;j<=vis[s[i]];++j)
			ans+=s[j];
		long long m=0;
		for(j=vis[s[i]]+1;j<=i;++j)
			m+=s[j];
		n-=vis[s[i]];
		for(j=vis[s[i]]+1;j<=vis[s[i]]+n%(i-vis[s[i]]);++j)
			ans+=s[j];
		cout<<ans+m*(n/(i-vis[s[i]]));
	}
}
