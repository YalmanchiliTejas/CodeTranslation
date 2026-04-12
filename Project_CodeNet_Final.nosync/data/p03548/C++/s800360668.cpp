#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x, y, z, l, count;
    while(scanf("%d%d%d", &x, &y, &z) != EOF)
	{
		l = 0, count = 0;
		for(int i = 1; ; i++ )
		{
			if(i % 2 != 0)
			{
				l += z;
			}
			else if(i % 2 == 0)
			{
				l += y;
				if((l + z) <= x) count++;
			}
			if(l >= x) break;
		}
		printf("%d\n", count);
	}
	return 0;
}
