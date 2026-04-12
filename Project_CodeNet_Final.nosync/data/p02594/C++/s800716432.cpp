#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define db double
#define ld long double
#define MOD 1000000007
#define inf (1LL << 62)
#define pi acos(-1.0)
#define si(a) scanf("%lld",&a)
#define sd(n) scanf("%lf", &n)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define pb(v,a) v.push_back(a)
#define pll pair <ll, ll>
#define mp make_pair
#define pbp(v,a,i) v.push_back(make_pair(a,i))
#define srt(v) sort(v.begin(),v.end())
#define rv(v) reverse(v.begin(),v.end())
#define ms(n, i) memset(n, i, sizeof(n))
#define debug printf("Debug\n");
#define en '\n'



#define _fastio  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
/*typedef tuple<ll,ll,ll>tpl;

ll bigmod(ll n,ll pow)
{
    if(pow==0)
        return 1;
    if(pow==1)
        return n%MOD;

    ll ans=bigmod(n,pow/2);
    ans=(ans*ans)%MOD;

    if(pow%2==1)
    {
        ans=(ans*n)%MOD;
    }
    return ans%MOD;
}

ll fact[1000005];

ll nCr(ll n,ll r)
{

    ll ans=fact[n];
    ans=(ans*bigmod(fact[r],MOD-2))%MOD;
    ans=(ans*bigmod(fact[n-r],MOD-2))%MOD;
    return ans;
} */

ll ar[100005];
int main()
{
    _fastio
    ll n;
    cin>>n;
    if(n>=30) cout<<"Yes"<<en;
    else cout<<"No"<<en;
}
