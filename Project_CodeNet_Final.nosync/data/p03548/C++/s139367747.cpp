#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int x, y, z;
	int res=0;
	int i, j;
	scanf("%d %d %d", &x, &y, &z);
	for (i = x - z; i >= y + z;)
	{
		i = i - z - y;
		res++;
	}
	printf("%d\n", res);
	return 0;
}