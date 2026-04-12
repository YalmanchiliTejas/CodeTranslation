#include<cstdio>

#define fmax(a,b) ((a)>(b)?(a):(b))

long long ans,n,k;

int main(){
	scanf("%lld%lld",&n,&k);
	if (k==0){
		printf("%lld\n",n*n);
		return 0;
	}
	for(register long long j=k+1;j<=n;j++){
		//printf("%lld %lld %lld\n",j,(j-k)*(n/j),n-(n/j)*j-k+1);
		ans+=(j-k)*(n/j)+fmax(n-(n/j)*j-k+1,0);
	}
	printf("%lld\n",ans);
}