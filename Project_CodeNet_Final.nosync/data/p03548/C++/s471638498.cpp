#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int x, y, z, num;
	scanf("%d %d %d",&x,&y,&z);
	num = x / (y + z);
	if(num * (y + z) + z > x)
		printf("%d",num - 1);
	else
		printf("%d",num);
}
