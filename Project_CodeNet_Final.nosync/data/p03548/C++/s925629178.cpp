#include<stdio.h>
int main(void) {
	int x, y, z;

	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);

	int i;
	int people = 0;
	for (i = 0; x >= y; i++) {
		x = x - z;
		if (x > y&&x-y>=z) {
			x = x - y;
			people++;
		}
		else {
			break;
		}
	}

	printf("%d\n", people);
	return 0;
}