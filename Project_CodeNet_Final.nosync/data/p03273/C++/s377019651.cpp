#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
int a[101][101],b[101],c[101];

int main()
{
     int n,m;
     std::cin>>n>>m;
     std::string s;
     for(int i=1;i<=n;i++)
     {
         std::cin>>s;
         for(int j=1;j<=m;j++)if(s[j-1]=='#')a[i][j]=1;
     }

     for(int i=1;i<=n;i++)
     {
         int p=0;
         for(int j=1;j<=m;j++)if(a[i][j])p=1;
         if(!p)b[i]=1;
     }

     for(int i=1;i<=m;i++)
     {
         int p=0;
         for(int j=1;j<=n;j++)if(a[j][i])p=1;
         if(!p)c[i]=1;
     }

     for(int i=1;i<=n;i++)
     {
         bool p=0;
         if(b[i])continue;
         for(int j=1;j<=m;j++)
         {
             if(c[j])continue;
             if(a[i][j])std::cout<<'#';
             else std::cout<<'.';
         }std::cout<<std::endl;
     }
}
