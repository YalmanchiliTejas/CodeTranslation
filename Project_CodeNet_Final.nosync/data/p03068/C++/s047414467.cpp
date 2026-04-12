#include<stdio.h>

int main(){
  	int N,K;
  	scanf("%d",&N);
  	char mozi[N],m[1];
  	scanf("%s",mozi);
  	scanf("%d",&K);
  	m[0] = mozi[K - 1];
  	for(int i = 0 ; i < N ; i ++){
    	if(mozi[i] != m[0]) mozi[i] = '*';
    }
  	printf("%s\n",mozi);
	return 0;
}