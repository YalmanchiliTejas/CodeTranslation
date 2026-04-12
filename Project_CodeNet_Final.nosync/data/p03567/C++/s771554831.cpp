#include <cstdio>
#include <cstring>
using namespace std;
char s[10];
int i;
int main()
{
	scanf("%s",s);int n=strlen(s);
	for (i=0;i<n-1;i++) if (s[i]=='A' && s[i+1]=='C'){
		puts("Yes");return 0;
	}puts("No");
	return 0;
}