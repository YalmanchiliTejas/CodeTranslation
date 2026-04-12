#include <stdio.h>

int main (){
	char A[11];
	scanf("%s", &A);
	if(A[0]==A[1] && A[1]==A[2])
	{ 
	puts("No"); 
	}
	else 
	{
	puts("Yes");	
	}
return 0;
}