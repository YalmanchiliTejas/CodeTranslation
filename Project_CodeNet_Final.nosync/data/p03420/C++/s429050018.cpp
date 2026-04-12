#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<sys/time.h>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int ri()
{
	register int x=0;register bool f=0;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();};
	return f?-x:x;
}
void wi(ll x)
{
	if(x<0)	x=-x,putchar('-');
	if(x>9)	wi(x/10);
	putchar('0'+x%10);
}

int main()
{
	ll n=ri(),k=ri(),a,b,l,r,mid;
	ll res=0;
	for(b=k+1;b<=n;b++)
	{
		for(a=0;a+b<=n;a+=b)
		{
			res+=min(b-k,n-a+1);
		//	printf("a=%d b=%d res=%lld\n",a,b,res);
		}
		l=a,r=n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(mid%b>=k)	r=mid-1;
			else	l=mid+1;
		}
		res+=n-l+1;
		if(k==0)	res--;
	}
	wi(res);putchar('\n');
	return 0;
}
