#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int X,Y,Z,n=0;
	scanf("%d %d %d",&X,&Y,&Z);
	X=X-Z;
        n=X/(Y+Z);
	printf("%d\n",n);
	return 0;
}