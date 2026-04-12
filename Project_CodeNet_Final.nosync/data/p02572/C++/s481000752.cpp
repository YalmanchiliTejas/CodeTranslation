#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<ll, ll>
#define endl "\n"
#define MAXN 100005
using namespace std;

ll n, x, m = 1e9 + 7;

ll modexp(ll x, ll y)
{
    ll res=1;
    while(y>0)
    {
        if(y%2==1) res=(res*x)%m;
        y/=2;
        x=(x*x)%m;
    }
    return res;
}

void solve()
{
    cin >> n;
    ll sum = 0, sqr = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        sum = (sum + x) % m;
        sqr = (sqr + (x * x) % m) % m;
    }
    sum = (sum * sum) % m;
    ll res = sum - sqr;
    while(res<0) res+=m;
    int t=modexp(2,m-2);
    cout << (res*t)%m << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}