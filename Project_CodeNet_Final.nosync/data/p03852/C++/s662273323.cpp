#include <stdio.h>
#include <iostream>
#include <string>
int main(void)
{
	char s;
	std::cin >> s;
	if (s == 'a' ||s=='i'|| s=='u'||s== 'e'||s== 'o')
	{
		std::cout << "vowel";
	}
	else
	{
		std::cout << "consonant";
	}
	return 0;
}
	

		
	