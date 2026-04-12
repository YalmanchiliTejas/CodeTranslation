#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	char sh[10];
	int f=0;
	scanf("%s",sh);
	for(int i=1;sh[i]!='\0';i++)
	if(sh[i]=='C'&&sh[i-1]=='A')
	{
		f=1;break;
	}
	if(f)printf("Yes\n");
	else printf("No\n");
	return 0;
}