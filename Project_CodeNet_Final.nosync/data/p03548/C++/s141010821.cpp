#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int x,y,z,n;
	while(scanf("%d%d%d",&x,&y,&z) != EOF)
	{
	n = (x-z)/(y+z);
	printf("%d",n);
	return 0;
}
}
