#include <stdio.h>

int main() {
	char A, B, C;
	scanf("%c %c %c", &A, &B, &C);
	
	if(A==B && A!=C)
	puts("Yes");
	
	if(B==C && B!=A)
	puts("Yes");
	
	if(A==C && B!=A)
	puts("Yes");
	
	if(A==B && A==C)
	puts("No");
	
	return 0;
}