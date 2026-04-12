#include <bits/stdc++.h>

bool solve(char c)
{
	char s[]{"aiueo"};
	for (int i = 0; i < 5; i++)
		if (c == s[i]) return true;
	return false;
}

int main()
{
	char c;
	scanf("%c", &c);
	if (solve(c)) printf("vowel\n");
	else printf("consonant\n");
	
	return 0;
}