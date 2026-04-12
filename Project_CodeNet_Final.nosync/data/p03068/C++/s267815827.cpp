#include<stdio.h>
int main(void)
{
	int a,c;
	char  b[11];
	int i;

	scanf("%d", &a);
	scanf("%s", &b);
	scanf("%d", &c);

	
	int target;

	target = b[c-1];
	for (i = 0; i < a; i++) {
		if (b[i] != target) {
			b[i] = '*';
		}
	}

	for (i = 0; b[i] != '\0'; i++) {
		printf("%c", b[i]);
	}
	printf("\n");
/**
	printf("%c\n", target);
	for (i = 0; i < 10; i++) {
		
	}*/
	

	return 0;
}