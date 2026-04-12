#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) ((x) & -(x))
#define BIT(a , b) (((a)>>(b)) & 1)

const ll MAXN=1e2+10;
const ll Mod=1e9+7;
const ll INF=1e9+10;

ll a[MAXN];

ll pw(ll x , ll n)
{
    if (n==0)
    {
        return 1;
    }

    ll w=pw(x , n/2);
    w*=w;
    w%=Mod;

    if (n&1)
    {
        w*=x;
        w%=Mod;
    }

    return w;
}

pll solve(ll l , ll r)
{
    if (l>r)
    {
        return mp(1 , 1);
    }

    ll res=0 , t=1 , w=1 , d=0 , e=INF;

    for(ll i=l;i<=r;i++)
    {
        e=min(e , a[i]);
    }

    ll z=l;

    for(ll i=l;i<=r;i++)
    {
        a[i]-=e;

        if (a[i]==0)
        {
            pll f=solve(z , i-1);

            t*=f.Y;
            t%=Mod;

            w*=f.X;
            w%=Mod;

            d++;
            z=i+1;
        }
    }

    pll f=solve(z , r);

    t*=f.Y;
    t%=Mod;

    w*=f.X;
    w%=Mod;

    res+=(pw(2 , d)*w)%Mod;
    res%=Mod;

    res+=(pw(2 , e)*t)%Mod;
    res%=Mod;

    res+=(t*((pw(2 , e)-2+Mod)%Mod))%Mod;
    res%=Mod;

    return mp(res , (pw(2 , e)*t)%Mod);
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin>>n;

	for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    pll res=solve(1 , n);

    cout<<(res.X-res.Y+Mod)%Mod;
}
