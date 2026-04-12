#include <cstdio>
#include <cmath>

using namespace std;

main()
{
	int x,y,z,n;
	scanf("%d %d %d",&x,&y,&z);
	n = (x-z)/(y+z);
	printf("%d",n);
}