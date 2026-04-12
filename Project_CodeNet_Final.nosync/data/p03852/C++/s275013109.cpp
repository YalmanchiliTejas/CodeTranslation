#include <cstdio>
using namespace std;
int s;
int main()
{
	scanf("%c",&s);
	if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')
		printf("vowel\n");
	else
		printf("consonant\n");
	return 0;
}