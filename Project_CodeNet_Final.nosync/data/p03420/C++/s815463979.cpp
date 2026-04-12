#include<cstdio>
typedef long long int ll;
int main(){
	ll n,k,ans = 0;
	scanf("%lld%lld",&n,&k);
	if(k==0){
		ans = n*n;
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=k+1;i<=n;i++){
		ll m = (n+1)/i;
		ans += (i-k)*m;
		ll t = n+1-m*i-k;
		if(t>0) ans += t;
	}
	printf("%lld\n",ans);
}
