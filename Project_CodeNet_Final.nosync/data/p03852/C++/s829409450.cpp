#include <cstdio>
char c;
int main ()
{
	scanf ("%c",&c);
	printf ("%s\n",c=='a'||c=='e'||c=='i'||c=='o'||c=='u'?"vowel":"consonant");
	return 0;
}
