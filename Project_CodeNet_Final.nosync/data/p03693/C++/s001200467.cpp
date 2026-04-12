#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int m,r,g,b;
    while(scanf("%d%d%d",&r,&g,&b)!=EOF)
    {
        m=r*100+g*10+b;
        if (m%4==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
