#include <stdio.h>
#include <stdlib.h>

int main(){
	char c;
	scanf("%c", &c);
	if(c == 'a' ||c == 'i' ||c == 'e' ||c == 'o' ||c == 'u'){
	printf("vowel");
	return 0;
	}
	printf("consonant");
	return 0;
}
