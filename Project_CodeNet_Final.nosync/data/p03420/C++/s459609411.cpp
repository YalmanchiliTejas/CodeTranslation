#include<stdio.h>

int _max(int a,int b){return a>b?a:b;}

int main(){
	
	long long ans=0;
	int n,k,i,a;
	scanf("%d%d",&n,&k);
	for(i=k+1;i<=n;i++){
		ans+=(long long)(n/i)*(i-k);
		ans+=(long long)_max(0,n%i-k+1);
	}
	if(k==0)ans=(long long)n*n;
	printf("%lld",ans);
	return 0;
}