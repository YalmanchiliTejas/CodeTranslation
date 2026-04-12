#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	long long int n,a[200000],i,x=0,y=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		x+=a[i];
		x%=1000000007;
	}
	for(i=0;i<n;i++){
		x-=a[i];
		if(x<0) x+=1000000007;
		y+=x*a[i];
		y%=1000000007;
	}
	printf("%lld\n",y);
	return 0;
}
