#include<cstdio>
using namespace std;
int ma[10][10];
void fil(int i,int j)
{
    if(ma[i+1][j]==1)
    {
        ma[i+1][j]=0;
        fil(i+1,j);
    }
    else
    {
        if(ma[i][j+1]==1)
        {
            ma[i][j+1]=0;
            fil(i,j+1);
        }
    }
}
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int n,m,i,j;
    char c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf(" %c ",&c);
            if(c=='#')
            {
                ma[i][j]=1;
            }
        }
    }
    if(ma[1][1]==1)
    {
        ma[1][1]=0;
        fil(1,1);
    }
    int p=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(ma[i][j]==1)
                p=1;
        }
    }
    if(p==0)
    {
        printf("Possible");
    }
    else
    {
        printf("Impossible");
    }
    return 0;
}
