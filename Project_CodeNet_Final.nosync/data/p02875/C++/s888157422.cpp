#include <bits/stdc++.h>

using namespace std;

#define MAX 10000005
#define ll long long
#define MOD 998244353
ll po[MAX];
ll C[MAX];
ll sum[MAX];

ll bigMod(ll a, ll p)
{
    if(p == 0) return 1LL;
    if(p == 1) return a;
    ll ret = bigMod(a, p/2);
    ret = (ret*ret)%MOD;
    if(p & 1) ret = (ret*a)%MOD;
    return ret;
}

ll dv(ll a, ll b)
{
    b = bigMod(b, MOD-2);
    ll ret = (a*b)%MOD;
    return ret;
}

int main()
{
    po[0] = 1;
    for(int i=1; i<MAX; i++){
        po[i] = (po[i-1]*2)%MOD;
    }
    ll n;
    scanf("%lld", &n);
    ll m = n/2;
    C[0] = 1;
    C[1] = m;
    for(int i=2; i<=m; i++){
        C[i] = (C[i-1]*(m-i+1))%MOD;
        C[i] = dv(C[i], i);
    }
    ll tot = 0;
    for(int i=0; i<=m; i++){
        tot += (C[i]*po[m-i])%MOD;
        tot = tot%MOD;
        sum[i] = tot;
    }
    ll ans = 0;
    for(int i=0; i<=m; i++){
        ll cur1 = (C[i]*po[m-i])%MOD;
        ll cur2 = (sum[m]-sum[m-i])%MOD;
        if(cur2 < 0) cur2 += MOD;
        ans += (cur1*cur2)%MOD;
        ans = ans%MOD;
    }
    ans = (ans*2)%MOD;
    ll all = 1;
    for(int i=1; i<=n; i++){
        all = (all*3)%MOD;
    }
    ans = (all-ans)%MOD;
    if(ans < 0) ans += MOD;
    cout << ans;
}