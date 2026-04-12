#include <stdio.h>
 
 
int main()
{
	int a, b;
	char c[10];
	int i;
	char tmp;
	scanf("%d\n", &a);
	for (i = 0; i < a; i++) {
		scanf("%c\n", &c[i]);
	}
	scanf("%d", &b);
    b = b - 1;
	tmp = c[b];
	for (i = 0; i < a; i++) {
		if (c[i] != c[b]) {
			c[i] = '*';
		}
		printf("%c", c[i]);
	}
	printf("\n");
    return 0;
}