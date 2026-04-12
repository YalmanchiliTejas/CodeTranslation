#include <bits/stdc++.h>
using namespace std;

#define S size()
#define EN end()
#define BE begin()
#define LEN length()

#define endl "\n"
#define cnt count
#define in insert
#define er erase
#define fi first
#define se second
#define ld double
#define ll long long

#define gcd __gcd
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define np next_permutation

#define si set<ll>
#define sc set<char>
#define mll map<ll,ll>
#define vi vector<ll>
#define vc vector<char>
#define pll pair<ll,ll>
#define vpi vector<pll>
#define msi multiset<ll>
#define msc multiset<char>
#define vvi vector<vector<ll> >

#define all(v) v.BE,v.EN
#define godv(v) sort(all(v))
#define god(ar,n) sort(ar,ar+n)
#define godvr(v) godv(v) ; reverse(all(v))
#define godr(ar,n) god(ar,n) ; reverse(ar,ar+n)

#define iter(s) for(auto it:s)
#define forl(i,n) for(ll i=0;i<n;i++)
#define fore(i,n) for(ll i=1;i<=n;i++)
#define fora(i,v) for(ll i=0;v[i];i++)
#define forn(i,n) for(ll i=n-1;i>=0;i--)
#define forls(i,l,r) for(ll i=l;i<r;i++)
#define forns(i,l,r) for(ll i=r-1;i>=l;i--)

#define pat ll n;cin>>n;
#define wq ll q;cin>>q;while(q--)
#define tak(s) string s;cin>>s;ll n=s.LEN;
#define nokay if(ok) cout<<"YES\n";else cout<<"NO\n";
#define pat1 ll n;cin>>n;ll ar[n];forl(i,n) cin>>ar[i];
#define pat2 ll n,k;cin>>n>>k;ll ar[n];forl(i,n) cin>>ar[i];

#define inf 1e18
#define mod1 1000000007
#define mod2 998244353
#define PI 3.1415926535897932384626433832
#define eness(x) __builtin_ctzll(x)//trailing 0s
#define nhigh(x) __builtin_popcountll(x)//number of high terms
//**********************************
void Fast();
ll mf(ll x,ll mod);
ll mi(ll x,ll mod);
ll C(ll n,ll r,ll mod);
ll bpow(ll a,ll b,ll mod);

void Fast(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}
ll mf(ll x,ll mod=mod1){
    if(x<2) return 1;
    return (x*mf(x-1))%mod;
}
ll mi(ll x,ll mod=mod1){
    return bpow(x,mod-2,mod);
}
ll C(ll x,ll y,ll mod=mod1){
    if(x<y) return 0;
    return (((mf(x)*mi(mf(y)))%mod)*mi(mf(x-y)))%mod;
}
ll bpow(ll x,ll y,ll mod){
    x%=mod;
    ll res=1;
    while(y>0){
        if(y&1){
            res=res*x%mod;
        }
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
//**********************************

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Fast();
    pat;
    if(n>=30){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
