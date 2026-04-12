#include<cstdio>
using namespace std;
int main()
{
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	r=100*r+10*g+b;
	if (r%4==0) printf("YES\n");
	else printf("NO\n");
 } 