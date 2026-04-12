#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;


int main()
{
   int n,i,j,k,h,w;cin>>h>>w;
   char m[h+1][w+1];
   bool vis[h+1][w+1];
   for(i=0;i<h;i++)
   {
       for(j=0;j<w;j++) vis[i][j]=true;
   }
   for(i=0;i<h;i++)
   {
       for(j=0;j<w;j++) cin>>m[i][j];
   }

   for(i=0;i<h;i++)
   {
       int c=0;
       for(j=0;j<w;j++)
       {
           if(m[i][j]=='.') c++;
       }
       if(c==w)
       {
           for(j=0;j<w;j++) vis[i][j]=false;
       }
   }
   for(j=0;j<w;j++)
   {
       int c=0;
       for(i=0;i<h;i++)
       {
           if(m[i][j]=='.') c++;
       }
       if(c==h)
       {
           for(i=0;i<h;i++) vis[i][j]=false;
       }
   }
   for(i=0;i<h;i++)
   {
       bool f=false;
       for(j=0;j<w;j++)
       {
           if(vis[i][j]) {cout<<m[i][j];f=true;}
       }
       if(f) cout<<endl;
   }
}
