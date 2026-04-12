#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int qsort_int_compare_ascend(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}
int qsort_int_compare_descend(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}
void ascendOrder(int size, int *array) {//sho-jun
	qsort(array, size, sizeof(int), qsort_int_compare_ascend);
}
void descendOrder(int size, int *array) {//ko-jun
	qsort(array, size, sizeof(int), qsort_int_compare_descend);
}

#define max(a,b) ((a>b)?(a):(b))
int main() {
	int N; cin >> N;
	int *x = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	ascendOrder(N, x);

	if (N % 2 == 0) {
		long long sum = 0;
		for (int i = 0, j = N - 1; i < j; i++, j--) {
			sum += x[j] - x[i];
		}
		sum *= 2;
		sum += x[N / 2 - 1] - x[N / 2];
		cout << sum;
	}
	else {
		long long sum1 = 0, sum2 = 0;
		for (int i = 1, j = N - 1; i < j; i++, j--) {
			sum1 += x[j] - x[i];
			sum2 += x[j - 1] - x[i - 1];
		}
		sum1 *= 2, sum2 *= 2;
		sum1 -= x[0] * 2;//M
		sum2 += x[N - 1] * 2;//W

		sum1 += x[N / 2] + x[N / 2 - 1];
		sum2 -= x[N / 2] + x[N / 2 + 1];

		cout << max(sum1, sum2);
	}

	delete[] x;
	return 0;
}