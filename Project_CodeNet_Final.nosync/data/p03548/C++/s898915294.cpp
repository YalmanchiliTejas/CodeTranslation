#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int x , y , z;
	scanf("%d %d %d",&x , &y , &z);
	x -= z;
	int sum = 0;
	sum = x / (y + z);
	printf("%d\n",sum);
}