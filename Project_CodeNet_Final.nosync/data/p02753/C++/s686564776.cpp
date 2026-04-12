#include <stdio.h>

int main()
{
	char A, B, C;
	scanf("%c%c%c", &A, &B, &C);
	
	if(A==B && B!=C || A==C && C!=B || B==C && C!=A)
 {	
	    puts("Yes");
 }
    else {
	    puts("No");
 }
    return 0;
 }