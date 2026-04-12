#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>

template<class T>
inline T _max(const T&a,const T&b)
{
	if(a<0)
		return b;
	return (a>b?a:b);
}
template<class T>
inline T _min(const T&a,const T&b)
{
	if(a<0)
		return b;
	return (a<b?a:b);
}

int N;
struct _b
{
	int x;int y;
	bool operator < (const _b&t2)const
	{
		if(x==t2.x)
			return y<t2.y;
		return (x<t2.x);
	}
}b[205050];

long long ans;
int rmx,rmn,bmx,bmn;
int totMAX,totMIN,tmxk,tmnk;

inline long long GetThisAns()
{
	if(rmx==-1)
		return LLONG_MAX;
	return (long long)(rmx-rmn)*(long long)(bmx-bmn);
}

inline void _swap(int&a,int&b)
{
	a+=b;
	b=a-b;
	a=a-b;
}

inline int getnum()
{
	char c=getchar();
	while(!(c>='0' && c<='9'))
		c=getchar();
	int a=0;
	while(c>='0' && c<='9')
	{
		a*=10;a+=c-'0';
		c=getchar();
	}
	return a;
}

int main()
{
	scanf("%d",&N);
	totMIN=LONG_MAX;totMAX=LONG_MIN;
	for(register int i=1;i<=N;i++)
	{
		b[i].x=getnum();b[i].y=getnum();
		if(b[i].x>b[i].y)
			_swap(b[i].x,b[i].y);
		totMAX=_max(totMAX,_max(b[i].x,b[i].y));
		totMIN=_min(totMIN,_min(b[i].x,b[i].y));
	}
	
	ans=LLONG_MAX;
	rmx=rmn=bmx=bmn=-1;
	
	// (rmx=totMAX && bmn=totMIN) || (rmn=totMIN && bmx=totMAX)
	long long nans=-1;
	rmx=rmn=bmx=bmn=-1;
	rmx=totMAX;bmn=totMIN;
	for(register int i=1;i<=N;i++)
	{
		bmx=_max(bmx,_min(b[i].x,b[i].y));
		rmn=_min(rmn,_max(b[i].x,b[i].y));
	}
	nans=GetThisAns();
	ans=_min(ans,nans);

	// (bmx=totMAX && bmn=totMIN) || (rmx=totMAX && rmn=totMIN)
	nans=-1;
	rmx=rmn=bmx=bmn=-1;
	bmx=totMAX;bmn=totMIN;
	std::sort(&b[1],&b[N+1]);
	rmx=b[N].x;
	int pmin=b[1].y;
	nans=rmx-rmn;
	for(register int i=1;i<N;i++)
	{
		rmx=_max(rmx,b[i].y);
		rmn=_min(pmin,_min(b[i].y,b[i+1].x));
		pmin=_min(pmin,b[i].y);
		nans=_min(nans,(long long)(rmx-rmn));
	}
	ans=_min(ans,nans*(long long)(bmx-bmn));
	
	
	printf("%lld\n",ans);
	
	return 0;
}