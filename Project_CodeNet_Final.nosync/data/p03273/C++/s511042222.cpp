#include<bits/stdc++.h>
using namespace std;
#define MAX         1000000 //10^5
#define ll          long long
#define bl          printf("\n")
#define pn(a)       printf("%d\n",a)
#define pc(a)       printf("%c\n",a)
#define pd(a)       printf("%lf\n",a)
#define pb(a)       push_back(a)
#define deb         printf("#####\n")
#define si(a)       scanf("%d",&a)
#define sii(a,b)    scanf("%d%d",&a,&b)
#define siii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sd(a)       scanf("%lf",&a)
#define sdd(a,b)    scanf("%lf%lf",&a,&b)
#define sddd(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define fl(a,n)     for(int i=a; i<n; i++)
#define rfl(n,a)    for(int i=n-1; i>=a; i--)

int t, cs, cnt, m, H, W, n, tmp, ans;
char hw[110][110];
int h[110], w[110];
int main()
{
    sii(H,W);
    fl(0,H)
    {
        for(int j=0; j<W; j++)
        {
            scanf(" %c",&hw[i][j]);
            if(hw[i][j] == '.')
            {
                h[i]++;
                w[j]++;
            }
        }
    }
    ///input done
    fl(0,H)
    {
        if(h[i] == W)
        {
            for(int j=0; j<W; j++)
            {
                hw[i][j] = 'x';
            }
        }
    }
    fl(0,W)
    {
        if(w[i] == H)
        {
            for(int j=0; j<H; j++)
            {
                hw[j][i] = 'x';
            }
        }
    }
    ///process done
    fl(0,H)
    {
        for(int j=0; j<W; j++)
        {
            if(hw[i][j] == 'x')
            {
                cnt++;
                continue;
            }
            printf("%c",hw[i][j]);
        }
        if(cnt != W)
            bl;
        cnt = 0;
    }


    return 0;
}
