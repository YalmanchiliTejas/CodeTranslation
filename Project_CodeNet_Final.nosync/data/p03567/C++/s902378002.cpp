#include<cstdio>
#include<cstring>
char a[10010];
int main()
{
	scanf("%s",a);
	int len=strlen(a)-1;
	for(int i=0;i<=len;++i)
	{
		if(a[i]=='A'&&a[i+1]=='C'){printf("Yes\n");return 0;}
	}printf("No\n");return 0;
}