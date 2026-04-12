#include <cstdio>

int main() {
	int A, B, C, X, Y;
	long sum = 0;
	scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
	while ((X > 0 || Y > 0) && A + B >= C*2) {
		sum += C*2;
		X--;
		Y--;
		if (!X)
			A = 0;
		if (!Y)
			B = 0;
	}
	while (X > 0) {
		sum += A;
		X--;
	}
	while (Y > 0) {
		sum += B;
		Y--;
	}
	printf("%ld\n", sum);

}
