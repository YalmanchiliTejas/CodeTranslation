#include<cstdio>
using namespace std;
#define ll long long
int n,k;
ll ans;
int main(void){
	register int i,j;
	scanf("%d%d",&n,&k);
	for(i=k+1;i<=n;++i)
		ans+=(n/i)*(i-k)+(n%i>=k?n%i-k+1-(k==0):0);
	printf("%lld\n",ans);
	return 0;
}