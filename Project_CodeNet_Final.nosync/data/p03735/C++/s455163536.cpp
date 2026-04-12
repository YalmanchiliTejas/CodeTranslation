#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
long long n,minid,maxid,mina,maxa,minb,maxb,ans;
struct node
{
	long long x,y;
}q[400005];
bool cmp(node t1,node t2)
{
	return (t1.x<t2.x || (t1.x==t2.x && t1.y<t2.y));
}
int main()
{
	scanf("%lld",&n);
	if (n==1)
	{
		printf("0\n");
		return 0;
	}
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld%lld",&q[i].x,&q[i].y);
		if (q[i].x>q[i].y) swap(q[i].x,q[i].y);
	}
	sort(q+1,q+n+1,cmp);
	minid=1;maxid=1;
    for(int i=2;i<=n;i++)
    {
        if (q[i].x<=q[minid].x && q[i].y>=q[maxid].y)
            maxid=minid=i;
        else if(q[i].x<q[minid].x) minid=i;
        else if(q[i].y>q[maxid].y) maxid=i;
    }
	mina=maxa=q[minid].x;
	minb=maxb=q[maxid].y;
	for (long long i=1;i<=n;i++)
	{
		maxa=max(q[i].x,maxa);
		minb=min(q[i].y,minb);
	}
	ans=(maxa-mina)*(maxb-minb);
	if (maxid!=minid)
	{
        maxa=q[maxid].y;mina=q[minid].x; 
        maxb=max(q[n].x,q[1].y);
        minb=min(q[1].y,q[2].x);
        long long premin=q[1].y,s=(long long)maxb-minb;
        for(long long i=2;i<n;i++)
        {
            maxb=max(q[i].y,maxb);
            minb=min(min(premin,q[i].y),q[i+1].x);
            premin=min(premin,q[i].y);
            s=min(s,maxb-minb);
        }
        s*=maxa-mina;
        ans=min(ans,s);
    }
    printf("%lld\n",ans);
	return 0;
}