#include <cstdio>
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
int main()
{
    int h,w;
    scanf ("%d %d",&h,&w);
    int cnt=0;
    for (int i=1;i<=h;i++)
    {
        getchar();
        for (int j=1;j<=w;++j)
        {
            char ch=getchar();
            if (ch=='#') 
            {
                ++cnt;
            }
        }
    }
    puts ((cnt==h+w-1) ? "Possible" : "Impossible");
    return 0;
}