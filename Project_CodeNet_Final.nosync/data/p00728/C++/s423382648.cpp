#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int i,j,in[100],hum,ans,mx=0,mn=1000;
    for(;scanf("%d",&hum),hum!=0;)
    {
        for(i=0,mx=0,mn=1000,ans=0;i<hum;i++)
        {
            scanf("%d",&in[i]);
            mx=mx<in[i]?in[i]:mx;
            mn=mn>in[i]?in[i]:mn;
            ans+=in[i];
        }
        ans=ans-(mn+mx);
        printf("%d\n",ans/(hum-2));
    }
    return 0;
}