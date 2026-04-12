#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, 1, -1, 1,-1,1,-1};
int dy[] = {1, -1, 0, 0, 1,-1,-1,1};
int m,n;
bool isSafe(int x, int y){
    if(x<0||y<0||x>=n||y>=m)return false;
    return true;
}

int main()
{

    int n,m,k,ans=0;
    scanf("%d %d %d",&n,&m,&k);
    while((n-=k)>=(m+k))
    {
        n-=m;
        ans++;
    }
    printf("%d",ans);
/*
 scanf("%d %d",&n,&m);
 char c[n][m];
 int x[n][m];
 for(int i=0;i<n;i++)
    fill(x[i],x[i]+m,0);

 for(int i=0;i<n;i++)
    scanf("%s",&c[i]);

 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         if(c[i][j]=='.')
         {
             //cout<<" i = "<<i<<" // "<<" j = "<<j<<endl;
             for(int k=0;k<8;k++)
             {
                 if(isSafe(i+dx[k],j+dy[k])&&c[i+dx[k]][j+dy[k]]=='#')
                 {
                     x[i][j]++;
                     //cout<<"x = "<<x[i][j]<<" i = "<<i+dx[k]<<" j ="<<j+dy[k]<<endl;
                 }
             }
         }
     }
 }
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(c[i][j]=='.')
            printf("%d",x[i][j]);
        else
            printf("%c",c[i][j]);
    }
    printf("\n");
}
*/
    return 0;
}
