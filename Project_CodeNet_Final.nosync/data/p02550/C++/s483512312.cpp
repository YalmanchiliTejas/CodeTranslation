#include <bits/stdc++.h>
using namespace std;
#define eni(x) template < class c > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
template < class c > struct rge { c b, e; };
template < class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; return * this; }
eni(==) return * this << range(begin(i), end(i)); }
template < class c, class b > debug & operator <<(pair < b, c > d) {
  return * this << "(" << d.first << ", " << d.second << ")";
}
template < class c > debug & operator <<(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  return * this << "]";
}
#else
template < class c > debug & operator <<(const c&) { return * this; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define mx 1000050
mt19937 myrand(time(0));

ll f(ll x, ll m){
    return (x*x)%m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(),cout.tie();
    ll n,x,m,sum=0;
    cin>>n>>x>>m;
    ll now=f(x,m),idx=0;
    vector<int> v,vis(m,0);
    while(!vis[now]){
        v.pb(now);
        vis[now]=++idx;
        now=f(now,m);
    }
    n--;
    ll sz=(int)v.size()-vis[now]+1;
    ll ans=x;
    for(int i=0;i<(vis[now]-1);i++){
        if(n==0) break;
        ans+=v[i];
        n--;
    }
    ll cnt=n/sz;
    for(int i=vis[now]-1;i<(int)v.size();i++) sum+=v[i];
    ans+=(cnt*sum);
    ll rem=n%sz;
    for(int i=vis[now]-1;i<(int)v.size();i++){
        if(rem==0) break;
        rem--;
        ans+=v[i];
    }
    cout<<ans<<endl;
    return 0;
}