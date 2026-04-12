#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int c[20];

int main()
{
	int n,ma = 0,mi = 0x3fffffff;
	scanf("%d%d%d",&n,&ma,&mi);
	if((ma * 10 + mi) % 4)printf("NO\n");
	else printf("YES\n");
}