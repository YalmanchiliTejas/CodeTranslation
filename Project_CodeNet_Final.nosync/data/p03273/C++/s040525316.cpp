#include <iostream>
#include <bits/stdc++.h>
#include <deque>
#include <vector>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    long long h,w,c=0,q=0;
    cin>>h>>w;
    char a[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>a[i][j];
    for(int i=0;i<h;i++)
    {
        c=0;
        for(int j=0;j<w;j++)
        {
            if(a[i][j]=='.') c++;
        }
        if(c!=w)
        {
           for(int j=0;j<w;j++)
            {
                q=0;
                if(a[i][j]=='.')
                {
                    for(int k=0;k<h;k++)
                    {
                        if(a[k][j]=='.') q++;
                    }
                    if(q!=h) cout<<a[i][j];
                }
                else cout<<a[i][j];
            }
            cout<<endl;

        }
    }
}
