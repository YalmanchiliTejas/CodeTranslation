#include<cstdio>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e2+9;
int main()
{
    bool del[MAXN][MAXN];
    char G[MAXN][MAXN];
    int n,m;
    memset(del,false,sizeof(del));
    scanf("%d%d",&n,&m);
    int st=0;
    int ed=0;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
            scanf(" %1c",&G[i][j]);
    }
    for(int i=0; i<n; ++i)
    {
        bool flag=false;
        for(int j=0; j<m; ++j)
        {
            if(G[i][j]!='.')
                flag=true;
        }
        if(!flag)
        {
            for(int j=0; j<m; ++j)
            {
                del[i][j]=true;
            }
        }
        else st=i;
    }
    for(int i=0; i<m; ++i)
    {
        bool flag=false;
        for(int j=0; j<n; ++j)
        {
            if(G[j][i]!='.')
                flag=true;
        }
        if(!flag)
        {
            for(int j=0; j<n; ++j)
            {
                del[j][i]=true;
            }
        }
    }
    for(int i=m-1;i>=0;--i)
    {
        if(del[st][i]==false)
        {
            ed=i;
            break;
        }
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(j!=ed)
            {
                if(!del[i][j])
                    printf("%c",G[i][j]);
            }
            else if(!del[i][j])
                printf("%c\n",G[i][j]);
        }
    }
    return 0;
}
