#include <stdio.h>

int main()
{
	char S[6]; scanf ("%s", S);
	int c[2] = { 0, };
	for (int i = 0; S[i]; i++) c[S[i] - 'A']++;
	puts(c[0] && c[1] ? "Yes" : "No");
	return 0;
}