#include <stdio.h>
int main() {
	char a[5];
	scanf("%s", a);
	(a[0] == a[1] && a[0] == a[2] && a[1]==a[2]) ? puts("No") : puts("Yes");
	return 0;
}