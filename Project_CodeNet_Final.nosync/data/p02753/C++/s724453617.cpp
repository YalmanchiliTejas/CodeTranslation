#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main()
{
	char s[4];
	scanf("%s",s);
	if (s[0] == s[1] && s[1] == s[2]) {
		printf("No");
	}
	else {

		printf("Yes");
	}
}
