#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
long a,b,c,x,y,n,m;
long sum=0;
int main(){
scanf("%ld",&a);
scanf("%ld",&b);
scanf("%ld",&c);
scanf("%ld",&x);
scanf("%ld",&y);
n=fminl(x,y);
m=labs(x-y);
if(a+b>=2*c){
sum+=2*c*n;
}else{
sum+=(a+b)*n;
}
if(x>y){
if(a>=2*c)
{sum+=m*2*c;
}else{
sum+=m*a;
}
}else{
if(b>=2*c)
{sum+=m*2*c;
}else{
sum+=m*b;
}
}
printf("%ld",sum);
}