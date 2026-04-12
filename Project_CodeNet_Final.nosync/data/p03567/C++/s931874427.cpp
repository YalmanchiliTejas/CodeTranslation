#include <cstdio>
#include <cstring>

char s[100];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	for (int i=0;i<n-1;i++)
		if (s[i]=='A' && s[i+1]=='C')
		{
			printf("Yes\n");
			return 0;
		}
	printf("No\n");
	return 0;
}