#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

ll modP(ll x, ll y, ll MOD)
{
    ll r = 1; x %= MOD; while (y > 0) {
        if (y & 1) {r = (r * x) % MOD;}
        y = y >> 1; x = (x * x) % MOD;
    } return r;
}
ll max(ll a, ll b) {return (a > b ? a : b);}
ll min(ll a, ll b) {return (a < b ? a : b);}
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " = " << arg1 << " | "; __f(comma + 1, args...);
}
ll gcd( ll a, ll b )
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd( b, (a % b) );
    }
}
ll lcm (ll a, ll b)
{
    ll ans = (a  / gcd(a, b)) * b;
    return ans;
}
void solve()
{
    ll ans = 0;
    ll x; 
    cin>>x; 
    if(x>=30) 
    cout<<"Yes\n"; 
    else 
    cout<<"No\n";
    //cout<<ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t ;
    t = 1;
//    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}



