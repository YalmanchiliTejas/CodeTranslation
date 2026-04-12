#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s, t, p, q, M, y;

int main()
{
    scanf("%lld%lld", &s, &t);
    scanf("%lld%lld%lld", &p, &q, &M);
    scanf("%lld", &y);
    ll Res=0, a=0;
    Res^=y;
    for (int i=2; i<=1e8; i++)
    {
        a=(a*p+q)%M;
        Res^=a;
    }
    printf("%lld\n", Res);
}

