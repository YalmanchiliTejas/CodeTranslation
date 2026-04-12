
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char c[4];

	scanf("%s",c);

	if(c[0]!=c[1])  {printf("Yes"); return(0);}
	if(c[1]!=c[2])  {printf("Yes"); return(0);}
	printf("No"); return(0);
}
