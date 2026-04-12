#include <stdio.h>
int main (void){
int N,a,b,c;
scanf("%d",&N);
a=800*N;
b=N%15;
b=200*(N-b)/15;
c=a-b;
printf("%d\n",c);
return 0;
}