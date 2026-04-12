#include <cstdio>
using namespace std;
const long long mod=1000000007;
int n;
int a[200005];
long long sum[200005];
long long cnt=0;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	sum[0]=a[0];
	for(int i=1;i<n;++i)sum[i]=a[i]+sum[i-1];
	for(int i=0;i<n;++i){
		cnt+=((sum[n-1]-sum[i])%mod*a[i])%mod;
		cnt%=mod;
	}
	printf("%lld\n",cnt);
	return 0;
}
