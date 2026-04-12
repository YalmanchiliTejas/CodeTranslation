#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x, y, z, len, count;
	while(scanf("%d %d %d", &x, &y, &z)!=EOF)
	{
		len = 0, count = 0;
		for(int i = 1; ; i++)
		{
			if(i % 2 != 0)
			{
				 len += z;
		    }
			else if(i % 2 == 0)
		    {
				 len += y;
				 if((len + z) <= x ) count++;
			}
	    	if(len >= x) break;
		}
		printf("%d\n", count);
	}
	return 0;
}
