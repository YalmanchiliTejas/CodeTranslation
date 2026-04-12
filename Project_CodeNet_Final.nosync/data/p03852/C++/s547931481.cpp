#include <stdio.h>

char c[1];
bool ans = false;

int main(void) {
	scanf("%c", &c);

	if (c[0] == 'a' || c[0] == 'e' || c[0] == 'i' || c[0] == 'o' || c[0] == 'u') {
		ans = true;
	}

	if (ans == true) { printf("vowel\n"); }
	else { printf("consonant\n"); }
	return 0;
}