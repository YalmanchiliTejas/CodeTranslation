#include <cstdio>
#include <cstring>
inline int read()
{
	register int c=getchar(),f=1,k=0;
	while (c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
char s[500];
int main()
{
	scanf("%s",s);
	bool flag=1;
	for (int i=1;i<strlen(s);i++)if (s[i-1]=='A'&&s[i]=='C')flag=0;
	if (!flag)printf("Yes\n");else printf("No\n");
} 