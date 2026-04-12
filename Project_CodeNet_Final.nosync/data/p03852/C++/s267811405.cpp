#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	char c;

	scanf("%s", &c);

	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
	{
		printf("vowel\n");
	}else
	{
		printf("consonant\n");
	}

	return 0;
}
	