#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main()
{
	char s[4];
	scanf("%s", &s);
	if (strchr(s, 'A') && strchr(s, 'B')) {
		printf("Yes");
	}
	else { printf("No"); }
	return 0;
}