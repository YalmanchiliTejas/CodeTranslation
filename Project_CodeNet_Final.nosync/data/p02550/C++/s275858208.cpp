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
const ll mod2= 998244353;
using namespace std;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
map<ll,ll> w;
ll n,x,m;

ll fc(ll st,ll p){
    ll pos=0;
    ll t=st;
    ll ans=0;
    while(pos<p){
        ans+=t;
        t=t*t;
        t%=m;
        pos++;
    }
    return ans;
}
int main(){
    ll ans=0;
    cin>>n>>x>>m;
    ll pos=0;
    ll t=x,st=0,e=0,now;
    while(w[t]==0&&pos<n){
        w[t]=pos;
        ans+=t;
        t=t*t;
        t%=m;
        pos++;
        now=t;
        e=w[t];
        st=pos-w[t];
       // cout<<t<<" "<<pos<<" "<<w[t]<<endl;
        
    }
   // cout<<ans<<endl;
    if(t==1)ans+=n-pos;
    else if(t!=0&&pos<n) {
        ll num=n-e;
        ll b=fc(x,e);
       // cout<<num<<endl;
        //cout<<b<<" "<<(ans-b)*(num/st)<<" "<<fc(now,num%st-1)<<endl;
        ans=b+(ans-b)*(num/st)+fc(now,num%st);
    }
    cout<<ans<<endl;
   // cout<<st;
}

