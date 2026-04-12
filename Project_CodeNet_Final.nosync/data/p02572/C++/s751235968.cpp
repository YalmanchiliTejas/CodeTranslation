#include<cstdio>
using namespace std;
int a[200005];
long long sum[200005];
int main(){
	int n,i;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		sum[i]%=1000000007;
	}
	for(i=n;i;i--){
		ans+=sum[i-1]*a[i]%1000000007;
		ans%=1000000007;
	}
	printf("%lld",ans);
	return 0;
}