#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X,Y,Z;
    int res=0,len=0;
    scanf("%d%d%d",&X,&Y,&Z);

    len+=Z;
    
    while(1)
    {
        len+=Y+Z;
        if(len>X)
            break;
        res++;
    }

    printf("%d\n",res);
}