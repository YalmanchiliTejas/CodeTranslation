#include <stdio.h>
#include <string>

int main()
{
	char in = 0;
	char boin[] = "aiueo";
	std::string out = "consonant";

	scanf( "%c", &in );

	for (auto& work : boin)
	{
		if (work == in)
		{
			out = "vowel";
			break;
		}
	}

	printf( "%s", out.c_str() );

	return 0;
}