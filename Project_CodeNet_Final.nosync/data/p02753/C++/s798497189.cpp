#include <cstdio>
#include <algorithm>

int main()
{
	char s[4];
	scanf("%s", s);
	if (*(unsigned int*)s == *(unsigned int*)"AAA" || *(unsigned int*)s == *(unsigned int*)"BBB")
	{
		puts("No");
	}
	else
	{
		puts("Yes");
	}

	return 0;
}
