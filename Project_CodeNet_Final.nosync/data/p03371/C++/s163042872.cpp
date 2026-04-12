#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
	int a, b, c , x, y;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	int ans1,ans2,ans3,ans4;
	ans2 = a * x + b * y;
	if(x >= y)
	{
		ans1 = y * c * 2 + (x - y) * a;
	}
	else
	{
		ans1 = x * c * 2 + (y - x) * b;
	}
	ans3 = max(x,y) * c * 2;
	printf("%d\n", min(ans3,min(ans1,ans2)));
	return 0;
}