#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define rg register
using namespace std;
template<typename T>inline void in(T &a)
{
	T ch=getchar(),f=1;
	for(a=0;!isdigit(ch);ch=getchar())
	  ch=='-'?f=-1:f=f;
	for(;isdigit(ch);ch=getchar())
	  a=(a<<3)+(a<<1)+ch-'0';
	a*=f;
}
template<typename T>inline void print(T x)
{
	if(x<0)
	  putchar('-'),x=-x;
	if(x>9)
	  print(x/10);
	putchar(x%10+'0');
}
long long a[55];
inline long long re(long long x)
{
	if(x<0)
	  return -1;
	long long tot=0;
	while(x>1)
	  tot++,x-=3,x/=2;
	return tot;
}
signed main()
{
	long long n,x;
	cin>>n>>x;
	long long r=1;
	a[0]=1;
	for(long long i=1;i<=n;i++)
	  r=3+2*r,a[i]=a[i-1]*2+1;
	long long mid,ans=0,l=1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(mid<=x)
		{
			long long tmp=re(mid-l-1);
			if(tmp>=0)
			  ans+=a[tmp];
			ans++;
			l=mid+1,r--;
		}
		else
		{
			l++,r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
