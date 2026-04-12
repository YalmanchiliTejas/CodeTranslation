#include<cstdio>
long long int max(long long int a,long long int b){
	if(a<b)return b;
	else return a;
}
int main(){
	long long int n,k;
	scanf("%lld%lld",&n,&k);
	long long int ans=0;
	for(int i=k+1;i<=n;i++){
		ans+=(n/i)*(i-k)+max((n%i)-k+1,0);
	}
	if(k==0)ans=n*n;
	printf("%lld\n",ans);
	return 0;
}