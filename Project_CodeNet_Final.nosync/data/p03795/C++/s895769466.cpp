#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n;

int main()
{
    while(~scanf("%d",&n))
    {
        int x=n*800;
        int y=(n/15)*200;
        printf("%d\n",x-y);
    }
}
