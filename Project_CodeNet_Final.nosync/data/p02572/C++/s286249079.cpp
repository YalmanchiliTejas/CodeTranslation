#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define INF 1000000000
#define pb push_back
#define sz(a) int((a).size())
#define all(c) c.begin(), c.end()
#define tr(c, i) for (typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

ll bigmod(ll a, ll b, ll m)
{

    if (b == 0)
        return 1;
    ll x = bigmod(a, b / 2, m);
    x = (x * x) % m;

    if (b % 2)
        x = (x * a) % m;
    return x;
}

ll bigsum(ll a, ll b, ll m)
{
    ll s;
    if (b == 0)
        return b;
    if (b == 1)
        return a + 1;
    if (b % 2)
    {
        b = b / 2;
        s = bigsum(a, b, m) % m;
        s = (s * bigmod(a, b + 1, m)) % m;
        return s;
    }
    else
    {
        s = bigsum(a, b - 1, m) % m;
        s = (a * s + 1) % m;
        return s;
    }
}


int main()
{
    ll i,s=0,p[200005],ara[200005],n,mod = 1000000007;
    cin>>n;

    for(i=1;i<=n;i++) cin>>ara[i];
    p[n+1] = 0;
    for(i=n;i>0;i--){
        p[i] = p[i+1]+ara[i];
        p[i] %= mod;
    }

    for(i=1;i<=n;i++){
        s += p[i+1] * ara[i];
        s %= mod;
    }

    cout<<s%mod<<endl;
    return 0;
}