#include<stdio.h>
int main(void) {
	int n, k;
	char str[20];
	int i, j;

	scanf("%d", &n);
	scanf("%s", str);
	scanf("%d", &k);

	for (i = 0; str[i] != '\0'; i++) {
		if (str[k-1] != str[i]) {
			str[i] = '*';
		}
	}
	printf("%s", str);
	return 0;
}