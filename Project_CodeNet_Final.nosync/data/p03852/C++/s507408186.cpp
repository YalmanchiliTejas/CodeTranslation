#include "stdio.h"
int main()
{
	char c=getchar();
	printf(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'?"consonant\n":"vowel\n");
}