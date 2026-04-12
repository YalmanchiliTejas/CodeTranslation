// Charan Sriramula
 
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int ll;
 
const ll lg=22;
const ll N=2e5+5;
const ll M=5e8;
const ll INF=1e18;
const ll mod=1e9+7;
const double PI = 3.14159265358979323846;
 
#define is(n) scanf("%d",&n)
#define io(n) printf("%d\n",n)
#define ls(n) scanf("%lld",&n)
#define lo(n) printf("%lld\n",n)
 
#define f first
#define s second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mp(x,y) make_pair(x,y)
#define GCD(a,b) __gcd((a),(b))
#define all(v) v.begin(),v.end()
#define bits(x) __builtin_popcount(x)
#define LCM(a,b) ((a)*(b))/GCD((a),(b))
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template<typename T> T power(T x,T y,ll m){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}
 
inline ll mul(ll a, ll b, ll p){ return (a * 1ll * b) % p; }
inline ll sub(ll a, ll b, ll p){ ll c = a - b; if(c < 0) c += p; return c; }
inline ll add(ll a, ll b, ll p){ ll c = a + b; if(c > p) c -= p; return c; }
 
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl


int main()
{
    ll n;
    cin>>n;
    ll ans=0;
    multiset<ll> s;
    while(n--)
    {
        ll x;
        cin>>x;
        if(s.size()==0||*s.begin()>=x)
        {
            ans++;
            s.insert(x);
        }
        else
        {
            auto lb=s.lower_bound(x);
            lb--;
            s.erase(lb);
            s.insert(x);
        }
    }
    cout<<ans<<endl;
}
