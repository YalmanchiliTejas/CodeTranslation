#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

ll mondiv(ll a,ll m){
    ll b=m;ll u=1;ll v=0;
    while(b){
        ll t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=m;
    if(u<0)u+=m;
    return u;
}

int main(){
    int n;cin>>n;
    ll r=(ll)0,sum=(ll)0;
    vll a(n);
    rep(i,n){
        cin>>a[i];
        r+=a[i]*a[i];
        r%=inf;
        sum+=a[i];
        sum%=inf;
    }
    ll ans=sum*sum;
    ans%=inf;
    ans-=r;
    if(ans<0)ans+=inf;
    ans*=mondiv((ll)2,inf);
    ans%=inf;
    cout<<ans<<endl;
}