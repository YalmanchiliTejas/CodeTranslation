#include <stdio.h>
int main(void)
{
	char s;
	scanf("%c",&s);
	if(s=='a' || s=='i' || s=='u' || s=='e' || s=='o'){
		printf("vowel\n");
	}else{
		printf("consonant\n");
	}
	return 0;
}