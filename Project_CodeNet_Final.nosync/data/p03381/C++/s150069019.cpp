#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

namespace gaw
{
	const int N=201000;

	int s[N],t[N],n;

	void solve()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i),t[i]=s[i];
		int a,b;

		std::nth_element(s+1,s+n/2,s+n+1),a=s[n/2];
		std::nth_element(s+1,s+n/2+1,s+n+1),b=s[n/2+1];

		for(int i=1;i<=n;i++)
			printf("%d\n",t[i]<=a?b:a);
	}
}

int main()
{
	gaw::solve();
	return 0;
}
