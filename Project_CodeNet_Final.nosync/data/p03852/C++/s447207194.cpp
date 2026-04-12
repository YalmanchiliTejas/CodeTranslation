#pragma GCC optimize(2)
#include <cstdio>
using namespace std;

int main()
{
	char s;
	scanf("%c",&s);
	if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u') printf("vowel\n");
	else printf("consonant\n");
	return 0;
}