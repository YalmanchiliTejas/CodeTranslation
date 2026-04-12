#include<bits/stdc++.h>

using namespace std;

struct num
{
    int n;
    int i;
    int si;
    bool operator < (num b) const
    {
        return n < b.n;
    }
};

num n[200005];
num sn[200005];
main()
{
    int nn;
    scanf("%d",&nn);
    int i;
    for(i=0;i<nn;i++)
    {
        scanf("%d",&n[i].n);
        n[i].i = i;
        sn[i] = n[i];
    }

    sort(sn,sn+nn);
    for(i=0;i<nn;i++)
    {
        n[ sn[i].i ].si = i;
    }

    for(i=0;i<nn;i++)
    {
        if(n[i].si < nn/2)
        {
            printf("%d\n",sn[nn/2]);
        }
        else
        {
            printf("%d\n",sn[nn/2-1]);
        }
    }
}
