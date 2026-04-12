#include<stdio.h>
int main()
{
	char A;
	char B;
	char C;
	scanf("%c %c %c",&A,&B,&C);
	if(A==B&&B==C&&C==A)
	printf("No");
	else if(A==B || B==C || C==A)
	printf("Yes");
	return 0;
}