#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;

int main(void) {
	int N, maxh, *mountains, answer = 1;
	scanf("%d", &N);
	mountains = (int *)malloc(sizeof(int));
	for (int i = 0; i < N; i++) {
		scanf("%d", mountains + i);
		if (!i) {
			maxh = mountains[0];
		}
		else {
			if (mountains[i] >= maxh) {
				answer++;
				maxh = mountains[i];
			}
		}
	}
	printf("%d", answer);
	return 0;
}