#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N,X;
ll siz[100];
ll cnt[100];

int main()
{
    scanf("%lld%lld",&N,&X);

    siz[0] = 1;
    for(int i = 1; i <= 50; i++)
    {
        siz[i] = siz[i - 1] * 2 + 3;
    }
    cnt[0] = 1;
    for(int i = 1; i <= 50; i++)
    {
        cnt[i] = cnt[i - 1] * 2 + 1;
    }

    ll ans = 0;
    for(int i = N; i >= 1; i--)
    {
        if(siz[i] == X)X--;
        if(X == 0)continue;
        if((siz[i] - 1) / 2 == X)
        {
            ans += cnt[i - 1];
            X = 0;
        }
        else if((siz[i] - 1) / 2 > X)
        {
            X--;
        }
        else
        {
            ans += cnt[i - 1] + 1;
            X -= siz[i - 1] + 2;
        }
    }
    if(X)ans++;

    printf("%lld\n",ans);
    return 0;
}
