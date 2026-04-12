#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char a[100000][8];

int main()
{
    int x,y,z;
    while(~scanf("%d%d%d",&x,&y,&z))
    printf("%d\n",(x-z)/(y+z));
}
