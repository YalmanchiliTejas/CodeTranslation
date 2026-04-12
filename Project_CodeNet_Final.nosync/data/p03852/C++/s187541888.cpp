#include <stdio.h>

int main(void) {
	char c;
	scanf("%c", &c);
	switch (c) {
		case 97:
		case 101:
		case 105:
		case 111:
		case 117:printf("vowel");break;
		default:printf("consonant");
	}
	return 0;
}