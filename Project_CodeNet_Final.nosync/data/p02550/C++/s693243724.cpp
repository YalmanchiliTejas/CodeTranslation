
/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back

#define eb emplace_back
#define mod    998244353
#define PI 2*acos(0.0)
#define all(r)(r).begin(),(r).end()
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define inf 1000000000000000000
#define N 500000
int dirx[] = {1, -1,0, 0, 1, 1, -1, -1}, diry[] = {0, 0, 1, -1, 1, -1, 1, -1};



//=============================================ASIFAZAD==============================================//

ll fun(ll x)
{
    return x*(x+1)/2;
}

int32_t main()
{
    io;
    ll n, x, m, cx;
    cin>>n>>x>>m;
    ll ans = 0, i = 0;
    cx = x;
    int cnt[m+5] = {};
    for(; i < n; i++)
    {
        if(cnt[x] || !x)
            break;
        cnt[x] = i;
        ans += x;
        x = (x*x)%m;
    }
    if(!x || i >= n)
        return cout<<ans, 0;
    ll first = 0;
    for(int a = 0;  a< cnt[x]; a++)
    {
        first +=  cx;
        cx = (cx*cx)%m;
    }

    ans -= first;
    n -= cnt[x];
    i -= cnt[x];


    ans = ans*(n/i);


    for(int j = 0; j < n%i; j++)
    {
        ans += x;
        x = (x*x)%m;
    }

    cout<<ans+first;
    return 0;
}
