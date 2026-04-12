#include<stdio.h>

int main(){
	char n;
	scanf("%c",&n);
	if(n == 'a' || n == 'e' || n == 'i' || n == 'u' || n == 'o') {
		printf("vowel");
	}
	else printf("consonant");
}