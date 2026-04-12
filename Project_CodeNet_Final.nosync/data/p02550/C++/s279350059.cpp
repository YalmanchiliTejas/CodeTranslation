#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORC(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define dd long double
ll mod;
inline ll md(ll x){
    return x<mod?x:x%mod;
}

ll power(ll x, ll y){
    if(y==0){
        return 1;
    }
    ll x_=power(x,y/2);
    if(y & 1){
        return md(md(x_*x_)*md(x));
    }
    else{
        return md(x_*x_);
    }
}

ll mod_inverse(ll x){
    return power(x,mod-2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,m;
    cin>>n>>x>>m;
    vector<ll> rem;
    rem.pb(x%m);
    ll last=x;
    map<ll,ll> ma;
    ma[last]=0;
    ll pos=0;
    for(ll i=1;i<=m;i++){
        last=(last*last)%m;
        if(ma.find(last)!=ma.end()){
            pos=ma[last];
            break;
        }
        rem.pb(last);
        ma[last]=i;
    }
    vector<ll> rep(rem.begin()+pos,rem.end());
    ll siz=rep.size();
    ll ans=0;
    for(ll i=0;i<min(n,pos);i++){
        ans+=rem[i];
    }
    n=max(0ll,n-pos);
    ll sum=0;
    for(auto & x:rep){
        sum+=x;
    }
    ans+=sum*(n/siz);
    n%=siz;
    for(ll i=0;i<n;i++){
        ans+=rep[i];
    }
    cout<<ans<<endl;
}
