#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

int x, y, z,i,k,q;

int main()
{
	scanf("%d%d%d",&x,&y,&z);
	q = y + z;
	k = 0;
	for(i = z;i <= x;i+=q)
		{
			k = k+1;
		}
	k = k-1;
	printf("%d\n", k);
	return 0;
}
