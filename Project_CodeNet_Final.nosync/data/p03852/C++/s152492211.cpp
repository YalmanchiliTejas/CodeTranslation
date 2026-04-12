#include <stdio.h>
#include <string.h>

int main(void)
{
	char c[10];

	scanf("%s", c);

	if (strcmp(c, "a") == 0 || strcmp(c, "i") == 0 || strcmp(c, "u") == 0 || strcmp(c, "e") == 0 || strcmp(c, "o") == 0)
	{
		puts("vowel");
	}
	else
	{
		puts("consonant");
	}

	return 0;
}