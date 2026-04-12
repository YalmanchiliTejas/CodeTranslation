#include <stdio.h>

int main () {
	char h1, h2, h3;
	scanf ("%c%c%c", &h1, &h2, &h3);
	
	if (h1 == h2 && h1 != h3) {
		puts("Yes");
	}
	else if (h1 == h3 && h1 != h2) {
		puts("Yes");
	}
	else if (h2 == h3 && h1 != h2) {
		puts("Yes");
	}
	else {
		puts ("No");
	}
	return 0;
}