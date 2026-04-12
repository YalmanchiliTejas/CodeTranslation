#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int X,Y,Z;
	int n,Q,W;
    scanf(" %d%d%d",&X,&Y,&Z);
	Q=X-2*Z;
	W=Y+Z;
	n=Q/W;
	if(Q%W>=Y)
		{n=n+1;}
		printf("%d",n);
		
}
