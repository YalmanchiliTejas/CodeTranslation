#include <stdio.h>

int main() {
	char a[10];
	scanf("%s", &a);
	
	(a[0] == a[1] && a[1] == a[2]) ? puts("No") : puts("Yes");
	
	return 0;
}