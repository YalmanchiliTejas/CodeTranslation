#include<stdio.h>
int main(void)
{
	int n,i,x,w;
	scanf("%d",&n);
	x=0;
	w=0;
	for(i=1;i<=n;i++){
		x+=800;
		w+=1;
		if(w%15==0){
			x=x-200;
		}
	}
	printf("%d\n",x);
	return 0;
}
