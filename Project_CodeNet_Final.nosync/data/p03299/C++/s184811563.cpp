#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

int n;
ll h[110];

ll power(ll a, ll n) {
    if (n<0) return 0;
    if (!n) return 1;
    ll t = power(a,n/2);
    return t*t%MOD*((n&1)?a:1)%MOD;
}

ll D[110][110];
ll ch[110];
vector<ll> comp;
int main() {
    int i, j;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%lld",&h[i]);
    for (i=0;i<n;i++) comp.push_back(h[i]);
    comp.push_back(0);
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    for (i=0;i<n;i++) ch[i] = lower_bound(comp.begin(),comp.end(),h[i])-comp.begin();
    for (j=0;j<comp.size();j++) {
        if (j==0) D[0][j] = power(2,h[0]);
        else if (j<=ch[0]) D[0][j] = power(2,h[0]-comp[j]+1);
        else D[0][j] = 0;
    }
    for (i=1;i<n;i++) {
        ll p = min(ch[i-1],ch[i]);
        for (j=0;j<comp.size();j++) {
            if (j<=p) D[i][j] = (D[i-1][j]+D[i-1][p])*power(2,h[i]-comp[p])%MOD;
            else D[i][j] = D[i-1][p]*2*power(2,h[i]-comp[j])%MOD;
        }
    }
    printf("%lld\n",D[n-1][0]);

    return 0;
}
