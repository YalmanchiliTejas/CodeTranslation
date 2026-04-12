#include <stdio.h>
int main(void) {
int r,g,b,a;
scanf("%d",&r);
scanf("%d",&g);
scanf("%d",&b);
a=100*r+10*g+b;
if(a%4==0){
  printf("YES\n");
}else{
  printf("NO\n");
}
	return 0;
}