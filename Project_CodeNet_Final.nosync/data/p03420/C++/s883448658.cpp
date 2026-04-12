#include<cstdio>
int main(){
	long long int n,k,a=0;
	scanf("%lld%lld",&n,&k);
	if(k==0){
		a=n*n;
	}
	else{
		for(int i=k+1;i<=n;i++){
			long long int j=0;
			while(j*i+k<=n){
				if((j+1)*i>n){
					a+=n-i*j-k+1;
				}
				else{
					a+=i-k;
				}
				j++;
			}
		}
	}
	printf("%lld\n",a);
}
