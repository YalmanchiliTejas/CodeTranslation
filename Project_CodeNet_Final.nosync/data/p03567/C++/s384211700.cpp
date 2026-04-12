#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[10];int f=0;
    scanf("%s",s);
	for(int i=1;s[i]!='\0';i++)
	
		if(s[i]=='C'&&s[i-1]=='A')
		{f=1;
		break;}
	if(f)
	printf("Yes\n");
		else printf("No\n");
	
	return 0;
}