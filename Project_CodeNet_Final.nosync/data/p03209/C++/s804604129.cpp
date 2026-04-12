#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[51],b[51],k,ans;
int n;
int main()
{
	a[0]=1;b[0]=1;for(int i=1;i<=50;++i) a[i]=a[i-1]*2+3,b[i]=b[i-1]*2+1;
	scanf("%d%lld",&n,&k);
	for(int i=n;i>=0;--i)
	if(a[i]+n-i<=k) {ans+=b[i];k-=a[i]+n-i;n=i;if(k) {++ans;k--;}}
	else if(k-n+i>=a[i]-i) {ans+=b[i];break;}
	printf("%lld",ans);
	return 0;
}