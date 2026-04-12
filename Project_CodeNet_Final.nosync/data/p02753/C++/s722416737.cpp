#include <stdio.h>

int main()
{
	char S[5];
	scanf ("%s", &S);
	
	((S[0] == S[1] || S[1] == S[2] || S[0] == S[2]) && (S[0] != S[1] || S[1] != S[2]) || S[0] != S[2]) ? 
        puts ("Yes") : puts ("No");
	
	return 0;
}