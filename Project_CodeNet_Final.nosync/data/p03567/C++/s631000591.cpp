#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	while(scanf("%s",s)!=EOF)
	{
		int n=strlen(s);
		bool flag=false;
		for(int i=0;i<n-1;i++)
		{
			if(s[i]=='A' && s[i+1]=='C')
			{
				flag=true;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}