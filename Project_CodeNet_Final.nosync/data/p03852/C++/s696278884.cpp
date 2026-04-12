#include<cstdio>
char n;
int main()
{
	scanf("%s",&n);
	if (n=='a'||n=='e'||n=='i'||n=='o'||n=='u')printf("vowel");
	else printf("consonant");
	return 0;
}