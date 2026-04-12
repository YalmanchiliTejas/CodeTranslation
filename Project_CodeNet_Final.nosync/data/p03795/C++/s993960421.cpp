#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <map>
#include <math.h>
#pragma warning(disable : 4996)


int main(void) {
	int n;
	scanf("%d", &n);

	printf("%d", n * 800 - (n / 15) * 200);
	return 0;
}
