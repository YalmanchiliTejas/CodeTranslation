#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define INF 999999999
#define ll long long
using namespace std;
ll n;
ll v[400005];
ll t[400005];//最大值 
ll o[400005]; //最小值 
ll lM,rM,lm=INF,rm=INF;
inline ll read()
{
  ll f=1,x=0;char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
  return x*f;
}
struct node
{
	ll ma,mi;
}p[200005];
ll ans=(ll)INF*(ll)INF;
bool cmp(node a,node b)
{
	return a.mi<b.mi;
}
int main()
{
	n=read();
  	for(int i=1;i<=2*n;i++)
    {
        v[i]=read();
    }
	for(int i=1;i<=n;i++)
	{
	    ll x1=max(v[2*i-1],v[2*i]);
	    ll x2=min(v[2*i-1],v[2*i]);
	    p[i].ma=x1,p[i].mi=x2;
		lM=max(lM,x1);
	    lm=min(lm,x1);
	    rM=max(rM,x2);
	    rm=min(rm,x2);
	}
	ll ans=(lM-lm)*(rM-rm);
 	if(lm>rM)
 	{
	 	printf("%lld\n",ans);
	 	return 0;
	 }
	sort(p+1,p+n+1,cmp);//属性值小的放在另一堆，排序 
	 t[1]=p[1].ma;
	 o[1]=p[1].ma;
	 for(int i=2;i<=n;i++)
	 {
 		t[i]=max(t[i-1],p[i].ma);
 		o[i]=min(o[i-1],p[i].ma);
 	} 
 	lm=rm;//从上向下交换左右属性值 
 	rM=max(rM,t[1]);
 	rm=min(p[1].ma,p[2].mi);
 	for(int i=2;i<=n;i++)
 	{
	 	ans=min(ans,(lM-lm)*(rM-rm));//最大与最小 
	 	rM=max(rM,t[i]);//维护一个最大值（交换） 
	 	rm=min(o[i],p[i+1].mi);//维护最大值（即前面最小的值和下一个的最小值） 
	 }
	 printf("%lld\n",ans);
	return 0;
}