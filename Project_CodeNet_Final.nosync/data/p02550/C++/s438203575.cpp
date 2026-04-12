#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 1000000007
using ll=long long;
const int INF=1000000000;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

struct IOSetup{
    IOSetup(){
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout<<fixed<<setprecision(12);
    }
} iosetup;
 
template<typename T1,typename T2>
ostream &operator<<(ostream &os,const pair<T1,T2>&p){
    os<<p.first<<" "<<p.second;
    return os;
}
 
template<typename T>
ostream &operator<<(ostream &os,const vector<T>&v){
    for(int i=0;i<(int)v.size();i++) os<<v[i]<<(i+1==(int)v.size()?"":" ");
    return os;
}

template<typename T1,typename T2>
istream &operator>>(istream &is,pair<T1,T2>&p){
    is>>p.first>>p.second;
    return is;
}

template<typename T>
istream &operator>>(istream &is,vector<T>&v){
    for(T &x:v)is>>x;
    return is;
}


signed main(){
    ll n,x,m;cin>>n>>x>>m;
    
    vector<ll> g(m);
    for(ll u=0;u<m;u++){
        g[u]=u*u%m;
    }

    ll res=0;
    vector<bool> check(m,false);
    int p=x;int loopst;
    check[p]=true;
    while(true){
        p=g[p];
        if(check[p]){
            loopst=p;
            break;
        }
        check[p]=true;
    }

    p=x;
    while(p!=loopst and n>0){
        res+=p;
        p=g[p];
        n--;
    }

    ll loopadd=0,loopsz=0;
    while(true){
        loopadd+=p;
        loopsz++;
        p=g[p];
        if(p==loopst) break;
    }
    res+=loopadd*(n/loopsz);

    n%=loopsz;
    if(n==0){
        cout<<res<<endl;
        return 0;
    }

    res+=p;
    p=g[p];
    n--;
    while(n--){
        res+=p;
        p=g[p];
    }
    cout<<res<<endl;
    return 0;
}
