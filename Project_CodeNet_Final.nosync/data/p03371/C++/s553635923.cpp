#include<stdio.h>
int main(void)
{
	int a,b,c,x,y,w,sum,sum1;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	sum=0; sum1=-1;
	if(a+b>c*2){
		if(x<y){
			sum1=y*2*c;
			w=x; y-=x; x=0;
		}
		else{
			sum1=x*2*c;
			w=y; x-=y; y=0;
		}
		sum+=w*2*c;
	}
	sum+=a*x;
	sum+=b*y;
	if(sum1!=-1&&sum>sum1) sum=sum1;
	printf("%d\n",sum);
	return 0;
}