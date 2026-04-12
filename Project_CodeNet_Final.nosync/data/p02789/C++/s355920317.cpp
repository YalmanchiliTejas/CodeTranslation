#include <stdio.h>

int main () {
	int N, M;
	scanf("%d %d", &N, &M);
	
	if (N > M) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	
	return 0;
}