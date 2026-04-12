#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;

int main()
{
    int x, y, z, b;
    float a;
    while(~scanf("%d %d %d", &x, &y, &z)){
    	y + 2 * z <= x;
    	a = (float)(x - z)/(y + z);
    	b = a;
    	printf("%d\n",b);
    }
    return 0;
}