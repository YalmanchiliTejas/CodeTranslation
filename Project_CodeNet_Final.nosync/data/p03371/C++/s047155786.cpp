#include <stdio.h>
int d(int i,int x)
{
	if(i>x){
		return 0;
	}else{
		return x-i;
	}
}
int main(void)
{
	int a,b,c,x,y,i,m,mini=2147483647;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	for(i=0; i<=100000; i++){
		m=i*2*c+d(i,x)*a+d(i,y)*b;
		if(mini>m){
			mini=m;
		}
	}
	printf("%d\n",mini);
	return 0;
}