#include<cstdio>
typedef long long LL;
int n;
LL a[55],ans,s,b[55];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",a+i);
	for(;;s=0){
		for(int i=1;i<=n;++i)s+=b[i]=a[i]/n,a[i]%=n;
		if(!s)break;
		ans+=s;
		for(int i=1;i<=n;++i)a[i]+=s-b[i];
	}
	printf("%lld\n",ans);
	return 0;
}