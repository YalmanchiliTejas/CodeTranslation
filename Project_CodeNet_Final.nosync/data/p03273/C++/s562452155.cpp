#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int col[111],row[111];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("o.txt","w",stdout);
    int h,w;
    cin>>h>>w;
    char a[h][w];

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>a[i][j];
        }
    }
  for(int i=0;i<h;i++)
    {
        int cn=0;
        for(int j=0;j<w;j++)
        {
           if(a[i][j]=='.') cn++;
        }
        if(cn==w) row[i]=1;
    }
    for(int i=0;i<w;i++)
    {
        int cn=0;
        for(int j=0;j<h;j++)
        {
           if(a[j][i]=='.') cn++;
        }
        if(cn==h) col[i]=1;
    }

for(int i=0;i<h;i++)
    {
        if(row[i]!=1){
        for(int j=0;j<w;j++)
        {
         if(col[j]!=1)  cout<<a[i][j];
        }
        cout<<endl;
        }
    }
    return 0;
}

