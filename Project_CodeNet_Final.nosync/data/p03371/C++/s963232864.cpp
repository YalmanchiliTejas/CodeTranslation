#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
int main()
{
    int a,b,c,x,y;
    int biao,ea,eb;
    int gmin,ans;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    biao = (a+b < 2*c) ? (a+b) : 2*c;
    ea =  (a<2*c) ?  a : 2*c;
    eb =  (b<2*c) ?  b : 2*c;
    x < y ? (ans = x*biao + (y-x)*eb ) :(ans = y*biao + (x-y)*ea );
    printf("%d\n",ans);
    return 0;
}
