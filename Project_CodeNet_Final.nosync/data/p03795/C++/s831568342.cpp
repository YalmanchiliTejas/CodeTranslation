#include<stdio.h>
int main(void)
{
    int n,a;
	scanf("%d",&n);
	a=n*800;
	while(1){
	    if(n>=15){
		    a=a-200;
			n=n-15;
		}
		if(n<15)break;
	}
	printf("%d\n",a);
	return 0;
}