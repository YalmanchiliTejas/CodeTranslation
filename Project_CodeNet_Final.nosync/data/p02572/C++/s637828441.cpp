#include<bits/stdc++.h>
using namespace std;

#define make_it_fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ll long long
#define ld long double
#define endl "\n"
#define ff first
#define ss second
#define imn INT_MIN
#define imx INT_MAX

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...) 20
#endif

ll power(ll a,ll b,ll m=1e9+7)
{
    a%=m;
    if(b==1)
    return a;
    if(b==0)
    return 1;
    ll ret=power(a,b/2);
    ret=(ret%m*ret%m)%m;
    if(b&1)
    ret=(ret%m*a%m)%m;
    return ret;
}

ll lcm(ll a,ll b)
{
    return (a*b)/(__gcd(a,b));
}

void solve()
{
    ll n,i,m=1e9+7;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    ll sum[n];
    sum[0]=a[0];
    for(i=1;i<n;i++)
    {
        sum[i]=(sum[i-1]+a[i])%m;
    }
    ll ans=0;
    for(i=0;i<n-1;i++)
    {
        ll z=(a[i]*(sum[n-1]-sum[i]+m)%m)%m;
        ans=(ans+z)%m;
    }
    cout<<ans<<endl;
}

int main()
{
    int TEST_CASES=1;
    // cin>>TEST_CASES;
    while(TEST_CASES--)
    {
        solve();
    }
    return 0;
}
