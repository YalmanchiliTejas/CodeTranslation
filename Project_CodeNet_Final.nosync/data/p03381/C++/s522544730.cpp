#include<bits/stdc++.h>
using namespace std;
int n,a[200005],l,r;
vector<int> v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	v.push_back(-1);
	sort(v.begin(),v.end());
	l=v[n/2];
	r=v[n/2+1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=r)
		{
			printf("%d\n",l);
		}else if(a[i]<=l)
		{
			printf("%d\n",r);
		}
	}
}