#include<cstdio>
#include<cstring>
using namespace std;

char s[11];

int main()
{
	scanf("%s",&s[1]); int len=strlen(s+1);
	bool flag=false;
	for (int i=1; i<len; ++i)
		if (s[i]=='A'&&s[i+1]=='C') {flag=1;break;}
	if (flag) printf("Yes"); else printf("No");
	return 0;
}