#include <stdio.h>

int main(int argc, char const *argv[]) {
	int x;

	scanf("%d", &x);

	if (x == 3 || x == 5 || x == 7) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
