#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A,B,C;
ll X,Y;

int main()
{
    scanf("%lld%lld%lld",&A,&B,&C);
    scanf("%lld%lld",&X,&Y);

    ll ans = 1001001001001001;
    for(int i = 0; i <= 200000; i += 2)
    {
        ll res = C * i;
        res += max(0LL,X - i / 2) * A;
        res += max(0LL,Y - i / 2) * B;
        ans = min(res,ans);
    }
    printf("%lld\n",ans);
    return 0;
}
