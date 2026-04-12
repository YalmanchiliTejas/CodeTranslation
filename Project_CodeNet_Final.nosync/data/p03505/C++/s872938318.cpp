#include<cstdio>
int main()
{
	long long k,a,b;
	scanf("%lld %lld %lld",&k,&a,&b);
	if(k>a&&b>=a){
		printf("-1\n");
	}else if(k<=a){
		printf("1\n");
	}else{
		long long ans;
		if((k-a)%(a-b)==0){
			ans=(k-a)/(a-b)*2+1;
		}else{
			ans=(k-a)/(a-b)*2+2+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}