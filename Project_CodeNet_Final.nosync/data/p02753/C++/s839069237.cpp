#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int num1,num2;
char s[5];
int main()
{
	scanf("%s",s+1);
	for (int i=1;i<=3;i++) if (s[i]=='A') num1++;else num2++;
	if (num1 && num2) printf("Yes\n");else printf("No\n");
return 0;
}