#include <iostream>
#include <cstdio>
#include <cstring>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int num = 100 * a + 10 * b + c;
	if (num % 4 ==0) puts("YES");
	else puts("NO");
	return 0;
}
