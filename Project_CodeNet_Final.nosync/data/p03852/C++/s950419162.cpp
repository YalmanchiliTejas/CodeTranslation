#include <stdio.h>

int main(){
	char c;
	
	scanf("%c", &c);
	puts(c=='a'|c=='i'|c=='u'|c=='e'|c=='o'?"vowel":"consonant");
	
	return 0;
}