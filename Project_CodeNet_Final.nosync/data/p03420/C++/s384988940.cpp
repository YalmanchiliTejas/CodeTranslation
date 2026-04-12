#include<cstdio>
#include<cstdlib>
int main(void){
	unsigned long i,N,K,sum=0;
	scanf("%lu%lu",&N,&K);
	for(i=K+1;i <= N;i++){
		if(N%i >=K && K > 0)sum += N - ((N/i)*K + K-1);
		else if(N%i >=K && K == 0)sum += N - ((N/i)*K);
		else sum += N - ((N/i)*K + N%i);
	}	
	printf("%lu\n",sum);
	fflush(stdout);
	return 0;
}