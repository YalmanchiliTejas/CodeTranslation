#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef complex<double> comp;
const ll inf=1e9+7;
const ll mod=1e9+7;
const int MAX=300010;

ll rui(ll a,ll b){
    ll res=1;
    ll x=a;
    while(b){
        if(b&1)res=res*x%mod;
        b/=2;
        x=x*x%mod;
    }
    return res;
}
signed main(){
    ll n;cin>>n;
    ll sum=0;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
        sum=(sum+a[i])%mod;
    }
    ll ans=0;
    rep(i,n){
        ans=(ans+(sum-a[i])%mod*a[i]%mod)%mod;
    }
    ans=ans*rui(2,mod-2)%mod;
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
}