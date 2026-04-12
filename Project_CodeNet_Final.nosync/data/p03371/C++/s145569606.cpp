#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int a,b,c,x,y;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    int sum1,sum2,sum3;
    sum1=a*x+b*y;
    if (x>y) sum2=c*2*y+(x-y)*a;
    else sum2=c*2*x+(y-x)*b;
    sum3=max(x,y)*2*c;
    printf("%d\n",min(sum3,min(sum1,sum2)));
    return 0;
}
