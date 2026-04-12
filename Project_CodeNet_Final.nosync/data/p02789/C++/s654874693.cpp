#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(b<a){
		printf("No");
	}
	else if(b>=a)
	    printf("Yes");
	    
	return 0;
}