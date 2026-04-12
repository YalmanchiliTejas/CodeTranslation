#include<stdio.h>
int main(){
	int a , b ;
	a = 0, b =0 ;

	scanf("%d", &a);
	scanf("%d", &b);

	if(a < b)printf("a < b\n");
	if(a > b)printf("a > b\n");
    if(a == b)printf("a == b\n");

   return 0;
}
 