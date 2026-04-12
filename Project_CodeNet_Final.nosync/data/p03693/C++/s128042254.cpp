#include<cstdio>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;
int main(void)
{
	int r,g,b;
	scanf("%d %d %d",&r,&g,&b);
	if((g*10+b)%4==0)	printf("YES\n");
	else printf("NO\n");
	return 0;
}
	