#include <stdio.h>

int main() {
	char a[11];
	scanf("%s", &a);
	
//	(a[0] == a[1] && a[1] == a[2]) ? puts("No") : puts("Yes");
	
	if(a[0] == a[1] && a[1] == a[2]) {
			puts("No");
		} else {
			puts("Yes");
		}
	
	return 0;
}