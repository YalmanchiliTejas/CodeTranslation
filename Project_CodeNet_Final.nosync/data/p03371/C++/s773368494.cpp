#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
  	const int cx = x;
  	const int cy = y;
    int maxp = 0;
    if (a + b > 2 * c)
    {
        maxp += c *2* min(x, y);
        if(x==min(x,y)){
      	y -= x;
        x =0;
        }else{
        x -= y;
        y = 0;
    	}
      	if (x > 0)
        {
            maxp += a * x;
        }
        if (y > 0)
        {
            maxp += b * y;
        }
      	if(maxp>2*c*max(cx,cy)){
        	maxp = 2*c*max(cx,cy);
        }
    }
    else
    {
        maxp += a * x + b * y;
    }
    cout << maxp << endl;
    return 0;
}