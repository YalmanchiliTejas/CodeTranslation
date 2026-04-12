#include <bits/stdc++.h>
#define L long long

using namespace std;

L n;
L a[222];

L operation(L x){
	L i;
	for(i=x+1;i<=n;i++)
	{
		swap(a[i],a[i-x]);
	}
}

L fin(L x){
	L i;
	for(i=1;i<=n;i++)
	{
		if(a[i]==x) return i;
	}
}

int main()
{
	scanf("%lld",&n);
	L i;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]++;
	}
	vector<L>ans;
	for(i=n;i>1;i--)
	{
		while(fin(i-1)!=1)
		{
			ans.push_back(1);
			operation(1);
		}
		while(fin(i)!=2)
		{
			ans.push_back(1);
			operation(1);
			ans.push_back(n-1);
			operation(n-1);
		}
	}
	printf("%lld\n",ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld\n",ans[i]);
	}
	/*for(i=1;i<=n;i++)
	{
		printf("%lld ",a[i]);
	}*/
}