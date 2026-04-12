#include <stdio.h>
#include <string.h>


int main ()
{
	char s[10];
	scanf("%s", s);
	
	(s[0] == s[1] && s[1] == s[2])  ? printf("No") : printf("Yes");
	
	return 0;
}