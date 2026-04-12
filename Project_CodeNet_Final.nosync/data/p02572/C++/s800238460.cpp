#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
const ld pi = 3.14159265358979323846;
const ll mod = 1000000007;
const ll inf = 1LL << 60;
 
int main() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
    }
    vector<ll> s(n+1, 0); //累積和
    rep(i,n){
        s[i+1]=s[i]+a[i];
    }
    ll ans=0;
    rep(i,n-1){
        ll sum=(s[n]-s[i+1])%mod;
        ans+=a[i]*sum;
        ans%=mod;
    }
    cout<<ans<<endl;
}