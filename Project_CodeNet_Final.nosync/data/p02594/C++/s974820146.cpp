#include <stdio.h>

	int main() {
		int x;
		scanf("%i", &x);
		
		(-40 <= x) && (x < 30) ? printf("No") : printf("Yes");
		
		return 0;
	}