//The Doc

#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long int ll;
typedef unsigned long long int ull;
#define fi first
#define se second
#define pb push_back
ll mod1=pow(10,9)+7;
int mod2=998244353;
ll inf=1e9;
ll maxxy=1e6+9;
typedef long double ld;
const double PI =  3.141592653589793238;

ll power(ll x, ll y, ll pp)
{
    ll res = 1;
    x = x % pp;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % pp;
        y = y>>1;
        x = (x*x) % pp;
    }
    return res;
}

ll modInverse(ll n, ll pp)
{
    return power(n, pp-2, pp);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll mod11=1e9+7;
    vector<ull> a(n+1);
    for (int i = 1; i <=n ; ++i) {
        cin>>a[i];
    }
    a[0]=0;
    vector<ull> b(n+1);
    for (int j = 0; j <=n ; ++j) {
        b[j]=a[j];
    }
    for (int k = 1; k <=n ; ++k) {
        b[k]+=b[k-1];
    }
    ull ans=0;
    for (int i = 1; i <n ; ++i) {
        ull k=(a[i]%mod11)*((b[n]-b[i])%mod11);
        ans+=k;
        ans%=mod11;
    }
    ans%=mod11;
    cout<<ans<<"\n";
    return 0;
}
