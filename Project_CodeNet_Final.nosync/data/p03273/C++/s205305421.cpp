#include <iostream>

using namespace std;
int n ,m,f,war[1001],you[1001];
bool s,w;
char arr[1001][10001];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='.')f++;
        }
        if(f==m)war[i]=i;
        f=0;
    }
  for(int k=1;k<=m;k++)
  {
    for(int h=1;h<=n;h++)
    {
        if(arr[h][k]=='.')f++;

    }
   if(f==n)you[k]=k;

   f=0;
  }

  for(int l=1;l<=n;l++)
  {
      for(int d=1,w=1;d<=m;d++)
      {
          if(war[l]!=l&&you[d]!=d)
          {  if(w==1&&l!=1&&s==1)
              {cout<<endl;
              }
              cout<<arr[l][d];
              w++;
              s=1;
          }

      }

  }
    return 0;
}
