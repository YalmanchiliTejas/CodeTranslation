#include <bits/stdc++.h>
using namespace std;

typedef long long  LL;
struct node{int x,y;}a[200010];
int n;
LL ans;
multiset <int> S1,S2;

bool cmp(node x,node y){return x.x<y.x;}

void work()
{
	scanf("%d",&n);
	if (n==1)  {puts("0");  return;}
	for (int i=1; i<=n; i++)
		{
			scanf("%d %d",&a[i].x,&a[i].y);
			if (a[i].x>a[i].y)  swap(a[i].x,a[i].y);
			S1.insert(a[i].x),S2.insert(a[i].y);			
		}
	ans=1LL*(*S1.rbegin()-*S1.begin())*(*S2.rbegin()-*S2.begin());
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<=n; i++)
		{
			S1.erase(S1.find(a[i].x)),S1.insert(a[i].y);
			S2.erase(S2.find(a[i].y)),S2.insert(a[i].x);
			ans=min(ans,1LL*(*S1.rbegin()-*S1.begin())*(*S2.rbegin()-*S2.begin()));
		}
	printf("%lld",ans);
}

int main()
{
	work();
	return 0;
}
