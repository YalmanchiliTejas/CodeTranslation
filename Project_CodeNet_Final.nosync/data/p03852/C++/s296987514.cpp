#include <stdio.h>

char s;

int main() {
	scanf("%c", &s);
	
	if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
		printf("vowel");
		return 0;
	}
	else{
		printf("consonant");
	}
	
	return 0;
} 