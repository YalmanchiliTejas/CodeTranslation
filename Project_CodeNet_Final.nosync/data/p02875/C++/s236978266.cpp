#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int long long
#define F first
#define S second
#define pii pair<int,int>
#define mpr make_pair

const int maxn = 1e7+10;
const int mod = 998244353;
const ll inf = 1e9+10;

int n;

int pw(int a, int b)
{
    if(b == 0) return 1;
    int x = pw(a,b/2); x = (x * 1ll * x) % mod;
    if(b & 1) x = (x * 1ll * a) % mod;
    return x;
}

int fac[maxn], repo[maxn];
int C(int n, int k)
{
    return (fac[n] * 1ll * ((repo[k] * 1ll * repo[n-k]) % mod)) % mod;
}

signed main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    fac[0] = repo[0] = 1;
    for(int i = 1; i <= n; i++)
        fac[i] = (fac[i-1] * 1ll * i) % mod;
    repo[n] = pw(fac[n], mod-2);
    for(int i = n-1; i >= 1; i--)
        repo[i] = (repo[i+1] * 1ll * (i+1)) % mod;

    int ans = pw(3,n);
    int power = 1;
    for(int k = 0; k <= n/2-1; k++)
    {
        (ans -= (2ll * ((C(n,k) * 1ll * power) % mod)) % mod) %= mod;
        (power *= 2) %= mod;
    }
    cout<< (ans + mod) % mod;
}


