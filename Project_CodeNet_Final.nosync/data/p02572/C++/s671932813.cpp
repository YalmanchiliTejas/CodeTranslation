#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
#define pll pair<ll,ll>
using ll=long long;
using ld=long double;
const ll INF = 1LL<<60;
const ll mod=1e9+7;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll a[1100000];
int main(){
    ll n;
    cin>>n;
    ll sum=0,ans=0;
    rep(i,0,n){cin>>a[i];sum+=a[i];}
sum%=mod;
    rep(i,0,n){
        sum-=a[i];
        if(sum<0)sum+=mod;
        ll pos=(sum*a[i])%mod;
        ans=(ans+pos)%mod;
    }
    cout<<(ans%mod);
}


