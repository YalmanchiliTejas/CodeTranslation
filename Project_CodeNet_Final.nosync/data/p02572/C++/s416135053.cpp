#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define req(i,a,b) for(ll i=(a);i>=(b);--i)
#define name "a"
#define pb push_back
#define sz size()
#define ff first
#define ss second
#define xd '\n'
#define dc " "
#define Truong_Thanh_Minh ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair < ll , ll > ii;
const ll maxn = 2e5+7, oo = 1e18, base = 311, mod = 1e9+7;
const double PI = 3.141592654;
ll t, n, a[maxn], s[maxn], res;
int main()
{
    Truong_Thanh_Minh
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    cin >> n;
    rep (i, 1, n)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        s[i] %= mod;
    }
    rep (i, 1, n - 1)
    {
        res += a[i] * ((s[n] - s[i] + mod)%mod);
        res %= mod;
    }
    cout << res;
}
