#include <cstdio>
int main()
{

		char a;
		scanf ("%c",&a);
		if (a-32 == 'A'||a-32 == 'E'||a-32 == 'I'||a-32 == 'O'||a-32 == 'U'){
		printf ("vowel\n");}
		else printf ("consonant\n");
	return 0;
	}