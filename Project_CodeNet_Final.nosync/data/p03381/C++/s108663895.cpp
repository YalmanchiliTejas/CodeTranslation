#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
#define inf 0x3f3f3f3f
struct node
{
	int a;
	int id;
}s[200050];
bool cmp(node a,node b)
{
	return a.a<b.a;
}
int ans[200050];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i].a);
		s[i].id=i;
	}
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(i<n/2)
		ans[s[i].id]=s[n/2].a;
		else
		ans[s[i].id]=s[n/2-1].a;
	}
	for(int i=0;i<n;i++)
	printf("%d\n",ans[i]);
	
	return 0;
}