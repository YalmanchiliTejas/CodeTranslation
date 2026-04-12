#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a = a*100+b*10+c;
    if(a%4==0)printf("YES");
    else printf("NO");
    return 0;
}
