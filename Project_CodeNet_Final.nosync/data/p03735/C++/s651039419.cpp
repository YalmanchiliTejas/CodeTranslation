#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e5+51;
const li inf=0x3f3f3f3f3f3f3f3f;
struct Tuple{
	li x,y;
	inline bool operator <(const Tuple &rhs)const
	{
		return this->x<rhs.x;
	}
};
Tuple p[MAXN];
ll cnt;
li res,res2,maxb,minb=inf,maxr,minr=inf;
li maxn[MAXN],minn[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
int main()
{
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		p[i].x=read(),p[i].y=read();
		if(p[i].x>p[i].y)
		{
			swap(p[i].x,p[i].y);
		}
		maxr=max(maxr,p[i].x),minr=min(minr,p[i].x);
		maxb=max(maxb,p[i].y),minb=min(minb,p[i].y);
	}
	res=(li)(maxr-minr)*(maxb-minb),minb=minr;
	sort(p,p+cnt),res2=inf;
	maxn[0]=minn[0]=p[0].y;
	for(register int i=1;i<cnt;i++)
	{
		maxn[i]=max(maxn[i-1],p[i].y),minn[i]=min(minn[i-1],p[i].y);
		if(i!=cnt-1)
		{
			res2=min(res2,max(maxn[i],p[cnt-1].x)-min(minn[i],p[i+1].x));
		}
	}
	res2*=(li)(maxb-minb);
	printf("%lld\n",min(res,res2));
}
