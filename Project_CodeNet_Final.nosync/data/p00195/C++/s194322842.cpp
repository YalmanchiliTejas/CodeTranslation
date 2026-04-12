#include <stdio.h>

int main(void) {
	int a[100], b[100];
	int i = 0;
	int max = 0;
	int maxbox = 0;
	char shop[] = { 'A','B','C','D','E' };

	while (1) {

		for (i = 0; i < 5; i++) {
			scanf("%d %d", &a[i], &b[i]);

			if (a[i] == 0 && b[i] == 0) {
				break;
			}
			if (i >= 1) {
				if (a[i] + b[i] > max) {
					max = a[i] + b[i];
					maxbox = i;
				}
			}
			else {
				max = a[i] + b[i];
				maxbox = i;
			}
		}
		if (a[i] == 0 && b[i] == 0) {
			break;
		}
		switch (maxbox) {
		case 0:
			printf("%c %d\n", shop[maxbox], max);
			break;
		case 1:
			printf("%c %d\n", shop[maxbox], max);
			break;
		case 2:
			printf("%c %d\n", shop[maxbox], max);
			break;
		case 3:
			printf("%c %d\n", shop[maxbox], max);
			break;
		case 4:
			printf("%c %d\n", shop[maxbox], max);
			break;
		default:
			break;
		}
	}

	return 0;
}
