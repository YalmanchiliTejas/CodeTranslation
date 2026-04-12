#include <stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	
	int b;
	scanf("%d",&b);
	
	if( a == b ){
		printf("Yes");
	}
	
	if( a > b ){
		printf("No");
	}
	return 0;
}