#include<cstdio>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int r,g,b;
    cin>>r>>g>>b;
    int a;
    a = r*100+g*10+b;
    if(a%4==0)
    {
        printf("YES\n");
    }
    else
        printf("NO\n");
    return 0;
}