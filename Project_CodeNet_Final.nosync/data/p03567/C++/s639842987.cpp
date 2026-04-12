#include<iostream>
#include<cstdio>
#include<cstring>

char s[10];

int main()
{
	int i;
	bool ans=false;
	scanf("%s",s);
	for(i=0;i<strlen(s)-1;i++) if(s[i]=='A'&&s[i+1]=='C') {ans=true;break;}
	if(ans) puts("Yes");
	else puts("No");
	return 0;
}
