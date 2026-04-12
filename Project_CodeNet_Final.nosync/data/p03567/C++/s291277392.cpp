#include<cstdio>
#include<cstring>
const int MAXN=50+5;
char a[MAXN];int l;
int main()
{
	scanf("%s",a+1);
	l=strlen(a+1);
	for(int i=1;i<l;i++)
		if(a[i]=='A' && a[i+1]=='C')
		{
			printf("Yes");
			return 0;
		}
	printf("No");
	return 0;
}