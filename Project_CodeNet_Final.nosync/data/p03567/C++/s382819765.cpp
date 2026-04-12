#include<cstdio>
#include<cstring>
const int N=1e5+10;
char s[N];
int main()
{
	int i;
	scanf("%s",s+1);
	int l=strlen(s+1);
	for (i=2;i<=l;i++)
	  if (s[i]=='C'&&s[i-1]=='A')
	  {
	    printf("Yes");
	    return 0;
		}
	printf("No");
}