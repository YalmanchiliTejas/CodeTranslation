#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int main()
{
	char c;
	scanf("%c",&c);
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	printf("vowel\n");
	else
	printf("consonant\n");
	return 0;
}
