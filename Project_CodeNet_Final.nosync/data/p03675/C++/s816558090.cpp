#include <cstdio>

int n;
int w[400040];

int main(void)
{
    int l,r,x;
    int i;
    bool reverse;

    //freopen("x.in","r",stdin);

    scanf("%d",&n);
    l = 200020;
    r = 200020 - 1;
    reverse = 0;
    for(i = 1;i <= n;++i)
    {
        if(reverse)
            scanf("%d",&w[--l]);
        else
            scanf("%d",&w[++r]);
        reverse ^= 1;
    }

    if(reverse)
        for(i = r;i >= l;--i)
            printf("%d%c",w[i]," \n"[i == l]);
    else
        for(i = l;i <= r;++i)
            printf("%d%c",w[i]," \n"[i == r]);

    return 0;
}