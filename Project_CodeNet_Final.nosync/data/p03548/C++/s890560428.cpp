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
	int x, y, z, i, sum = 0, count = 0;
    scanf("%d %d %d",&x, &y, &z);
    for(i = 1; ;i++)
	{
		sum = sum + y + z;
		if(sum + z <= x)
			count ++;
	    else
	    	break;
	}
	printf("%d\n",count);
	return 0;
}