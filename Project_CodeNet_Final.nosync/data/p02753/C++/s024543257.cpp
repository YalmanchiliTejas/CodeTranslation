#include <stdio.h>

int main() {
	char A, B, C;
	scanf("%c %c %c", &A, &B, &C);
	
	if(A==B && A==C)
	puts("No");
	
	else
	puts("Yes");
	
	return 0;
}