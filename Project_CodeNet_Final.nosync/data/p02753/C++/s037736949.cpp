#include<bits/stdc++.h>
using namespace std;
char s[10];
int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	int a=0; int b=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='A') a++;
		else b++;
	}
	if(a&&b) printf("Yes\n");
	else printf("No\n");
	return 0;
}