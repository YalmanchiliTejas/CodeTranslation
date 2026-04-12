#include <cstdio>
int n,m,ans,q1,q2;
bool passed[10];
bool edge[10][10];
void f(int last,int pass)
{
    if(pass < n)
    {
        for(int i = 2;i <= n;i++)
            if(!passed[i] && edge[i][last])
            {
                passed[i] = true;
                f(i,pass+1);
                passed[i] = false;
            }
    }
    else ans++;
}
main()
{
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d",&q1,&q2);
        edge[q1][q2] = edge[q2][q1] = true;
    }
    passed[1] = true;
    f(1,1);
    printf("%d\n",ans);
}
