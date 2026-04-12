#include<stdio.h>
int main (void)
{
	int a,b;
	
	scanf("%d %d",&a,&b);         	// scanf("%d",&a); // 
	
    
    if(a>b)
    {
		printf("a > b\n");        // a b //
	}
	
	if(a<b)
	{
		printf("a < b\n");
	}
	
	else if(a==b)
	{
		printf("a == b\n");
	}
	
	return 0;
}