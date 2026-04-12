#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define mx 1000002
mt19937 myrand(time(0));

ll bigmod(ll a, ll p, ll m){
    ll res=1,x=a;
    while(p){
        if(p&1) res=(res*x)%m;
        x=(x*x)%m;
        p=p>>1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(),cout.tie();
    ll n,sum=0;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
    ll ans=0;
    for(int i=0;i<n;i++){
        ll rem=(sum-a[i])%mod;
        rem=(rem*a[i])%mod;
        ans=(ans+rem)%mod;
    }
    ans=(ans*bigmod(2,mod-2,mod))%mod;
    cout<<ans<<endl;
    return 0;
}
