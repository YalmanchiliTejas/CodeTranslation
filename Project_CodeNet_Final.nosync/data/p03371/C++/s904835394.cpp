#include <bits/stdc++.h>

#include <math.h>
#include <stdio.h>

using namespace std;

int main(void) {
	int a, b, c, x, y;
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);

	int min = a*x + b*y;
	
	for (int i = 1; i <= x || i <= y; i++) {
		int f = a * (x-i<0?0:x-i) + b * (y-i<0?0:y-i) + 2*c*i;
		if (min > f) min = f;
	}

	printf("%d\n", min);
	return 0;
}
