#include<iostream>
#include<cstdio>
#include<algorithm>

int main()
{
    int r,g,b;
    while(scanf("%d%d%d",&r,&g,&b)==3){
        int ans=0;
        ans=r*100+g*10+b;
        if ((ans%4==0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
