#include<cstdio>
typedef long long ll;
ll a[51],t[51],k,n,tot,sum;
int main(){
//	freopen("ex.in","r",stdin);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	while(1){
		tot=sum=0;
		for(int i=1;i<=n;++i) if(a[i]<=n-1) tot++;
		if(tot==n) break;
		for(int i=1;i<=n;++i){
			t[i]=a[i]/n;
			sum+=t[i];
		}
		k+=sum;
		for(int i=1;i<=n;++i) a[i]=a[i]-t[i]*n+sum-t[i];
	}
	printf("%lld",k);
	return 0;
}