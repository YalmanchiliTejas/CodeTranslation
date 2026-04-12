#include<bits/stdc++.h>
#define N 200005
#define mod 1000000007
using namespace std;
template<typename T>
inline void in(T &x)
{
	x=0;
	char c=getchar();
	bool fu=0;
	while(c<'0'||c>'9'){if(c=='-')fu=1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
int n,a[N],sum[N],ans;
int main()
{
	in(n);
	for(int i=0;i<n;++i)in(a[i]);
	sum[n-1]=a[n-1];
	for(int i=n-2;i>=0;--i)sum[i]=(a[i]+sum[i+1])%mod;
	for(int i=0;i<n-1;++i)ans=(ans+(1LL*a[i]*sum[i+1]%mod))%mod;
	printf("%d\n",ans);
	return 0;
}