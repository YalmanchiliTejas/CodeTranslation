#include<cstdio>
#include<cstring>
char a[10];
int main()
{
	scanf("%s",a);
	int len=strlen(a);
	for(int i=1;i<len;i++)
	{
		if(a[i-1]=='A'&&a[i]=='C')	
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No");
	return 0;
}