#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>
#define ll long long
#define read freopen("input","r",stdin)
#define write freopen("output","w",stdout)
#define fr first
#define sc second
#define ii pair < int , int >
using namespace std;
int main()
{
 int n,m;
 cin>>n>>m;
 char a[n+1][m+1];
 for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
     cin>>a[i][j];
 int vis[n+1][m+1];
 memset(vis,0,sizeof(vis));
 vis[0][0] = 1;
  int x = 0 , y = 0;
 while(1)
 {

   if(x >=n  && y >= m)
    break;
   if(a[x+1][y] == '#')
   {
     vis[x+1][y] = 1;
      x++;
   }
   else if(a[x][y+1] == '#')
   {
       vis[x][y+1] = 1;
       y++;
   }
   else
    break;
 }
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         if(a[i][j] == '#' && vis[i][j] == 0)
         {
             cout<<"Impossible";
             return 0;
         }
     }
 }
 cout<<"Possible";

}
