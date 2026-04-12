#include <stdio.h>

int main(void)
{
	char s[2] = {'\0', '\0'};
	
	scanf("%s", s);
	if ((s[0] == 'a') || (s[0] == 'e') || (s[0] == 'i') || (s[0] == 'o') || (s[0] == 'u') ) 
		printf("vowel");
	else
		printf("consonant");
	
	return 0;
}
