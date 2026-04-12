#include <stdio.h>
int main(){
	long long p=0;
	int a,b,c,x,y,i,j,k,l;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	if(a+b<=2*c){
	printf("%d",a*x+b*y);
	return 0;
	
}
k=x;
if(k>y)k=y;
p=k*2*c;
x-=k;
y-=k;
if(x>0){
if(a>2*c)p+=2*c*x;
 else p+=a*x;
}
if(y>0){
if(b>2*c)p+=2*c*y;
 else p+=b*y;	
}
printf("%lld",p);
return 0;
}