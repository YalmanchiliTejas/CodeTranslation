#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
int MAXN = 1e5;
using namespace std;
int main()
{
	int  x , y , z;
	int n=1;
	while(scanf("%d %d %d",&x,&y,&z) != EOF)
	{
		//getchar();
		if ( ( x < 1 ) ||  ( z > MAXN )  ||  ( y + 2*z > x ) )	continue;
		while(   ( x - n*y - ( n + 1 )*z )  >=  0    )
		{
			n = n + 1;
		}
		printf("%d\n", n - 1 );
		n = 1;
	}
}