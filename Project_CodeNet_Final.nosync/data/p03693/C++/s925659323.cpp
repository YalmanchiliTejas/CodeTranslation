#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int r,g,b;
    while(~scanf("%d%d%d",&r,&g,&b))
    {
        if((r*100+g*10+b)%4==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
