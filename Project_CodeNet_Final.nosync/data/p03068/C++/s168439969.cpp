#include<stdio.h>
int main(void) {

	int i;
	int k, n;
	char s[100000];

	scanf("%d", &n);

	scanf("%s", s);

	scanf("%d", &k);

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != s[k - 1])s[i] = '*';
		printf("%c", s[i]);
	}

	printf("\n");

	return 0;
}