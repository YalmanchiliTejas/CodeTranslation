#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>

#define N 128

int main(void) {
	while(1) {
		int n;
		int s[N];
		int sum = 0, max, min, point;
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 0; i < n; i++) {
			scanf("%d", &s[i]);
		}
		max = min = s[0];
		for(int i = 0; i < n; i++) {
			sum += s[i];
			if(s[i] > max) max = s[i];
			if(s[i] < min) min = s[i];
		}
		point = (sum - max - min) / (n - 2);
		printf("%d\n", point);
	}
	return 0;
}