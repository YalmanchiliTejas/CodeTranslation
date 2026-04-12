#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int sll;
typedef long double ld;
#define A 1000000007ll
#define D 100000000000000ll
#define B 998244353ll
#define C 1000000000000000000ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define sor(v) sort(v.begin(),v.end())
#define sorrev(v) sort(v.begin(),v.end(),greater<ll>())
#define uni(v) unique(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define ve vector
#define br break
#define PI acos(-1)
#define subt cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n" 
auto random_address = [] { char *p = new char; delete p; return sll(p); };
const sll SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);

int main()
{
    FAST;
    ll n,x,m;
    cin>>n>>x>>m;
    ll pe=0,ch=x;
    ve<ll> a,mp(m,0);
    sll sum=0;
    while(mp[ch]==0)
    {
        a.pb(ch);
        mp[ch]=1;
        ch=(ch*ch)%m;
        pe++;
    }
    if(n<=pe)
    {
        for(ll i=0;i<n;i++)
            sum=(sum+a[i]);
        cout<<sum;
        return 0;
    }
    ch=0;
    ll xx=(a[pe-1]*a[pe-1])%m;
    while(a[ch]!=xx)
    {
        sum+=a[ch];
        ch++;
    }
    ll in=ch;
    ch=0;
    for(ll i=in;i<pe;i++)
        ch+=a[i];
    pe=pe-in;
    n-=in;
    sum+=(n/pe)*ch;
    n%=pe;
    ch=a[in];
    for(ll i=0;i<n;i++)
    {
        sum=(sum+ch);
        ch=(ch*ch)%m;
    }
    cout<<sum;
    subt;
    return 0;
}
