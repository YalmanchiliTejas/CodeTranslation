/*
srt: 2017年05月01日 22時15分42秒
end: 2017年05月01日 23時09分22秒
*/

#include<cstdio>
#include<algorithm>
inline void read(int&r)
{
	register char c;r=0;
	do c=getchar();while(c<'0'||c>'9');
	do r=r*10+c-'0',c=getchar();while(c>='0'&&c<='9');
}

typedef long long ll;

#define x a[i].first
#define y a[i].second
typedef std::pair<int,int> pii;

pii a[200000];

int main()
{
	int n,i,l=1e9,r=1,s=1,t=1e9;read(n);
	for(i=0;i<n;i++)
	{
		read(x),read(y);
		if(x>y)x^=y^=x^=y;
		if(x<l)l=x;
		if(y>r)r=y;
		if(x>s)s=x;
		if(y<t)t=y;
	}

	ll ans=(ll)(s-l)*(r-t),tmp=r-l,now;
	std::sort(a,a+n);
	for(i=0;i<n;i++)
	{
		if(x>t)
		{
			if((now=tmp*(s-t))<ans)ans=now;
			break;
		}
		if((now=tmp*(s-x))<ans)ans=now;
		if(y>s)s=y;
	}
	printf("%lld\n",ans);
}