#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100005;
int n;
long long x;
long long f[N];
long long l[N];
long long calc(int d,long long r)
{
	if (r<=0)
		return 0;
	if (!d)
		return r>0;
	long long ret=0;
	if (r>=l[d-1]+1)
		ret+=f[d-1];
	if (r<l[d-1]+1)
		ret+=calc(d-1,r-1);
	if (r>=l[d-1]+2)
		ret+=calc(d-1,r-l[d-1]-2)+1;
	return ret;
}
int main()
{
	scanf("%d%lld",&n,&x);
	f[0]=1;
	l[0]=1;
	for (int i=1;i<=n;i++)
	{
		f[i]=2ll*f[i-1]+1;
		l[i]=2ll*l[i-1]+3;
	}
	printf("%lld\n",calc(n,x));
	return 0;
}