#include <cstdio>
using namespace std;
const long long NR=4;
char s[NR];
int main()
{
	scanf("%s",s);
	if(s[0]=='A'&&s[1]=='A'&&s[2]=='A')
	{
		printf("No");
		return 0;
	}
	if(s[0]=='B'&&s[1]=='B'&&s[2]=='B')
	{
		printf("No");
		return 0;
	}
	printf("Yes");
	return 0;
}