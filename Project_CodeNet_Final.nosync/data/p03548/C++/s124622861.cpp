#include <cstdio>

int main() {
	int X, Y, Z;
	scanf("%d %d %d", &X, &Y, &Z);
	int sum = 0;
	int end = Z;
	for (int i = 0; ; i++) {
		end += Y + Z;
		if (end > X)
			break;
		sum++;
	}
	printf("%d\n", sum);
}
