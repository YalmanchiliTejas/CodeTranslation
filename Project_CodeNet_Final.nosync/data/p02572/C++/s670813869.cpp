#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T> ostream& operator<<(ostream& s,const multiset<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1'000'000'007;
const ll inf=1'000'000'000'000'000'00;
const int INF=1'000'000'000;
const double EPS=1e-10;
const double PI=acos(-1);

struct mint{
    ll x;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint& operator+=(const mint a){
        if((x+=a.x)>=mod) x-=mod;
        return *this;
    }
    mint& operator-=(const mint a){
        if((x+=mod-a.x)>=mod)x-=mod;
        return *this;
    }
    mint& operator*=(const mint a){(x*=a.x)%=mod;return *this;}
    mint operator+(const mint a) const{return mint(*this)+=a;}
    mint operator-(const mint a) const{return mint(*this)-=a;}
    mint operator*(const mint a) const{return mint(*this)*=a;}
    mint pow(ll t) const{
        if (!t) return 1;
        mint a=pow(t>>1);
        a*=a;
        if(t&1) a*=*this;
        return a;
    }
    // for prime mod
    mint inv() const{return pow(mod-2);}
    mint& operator/=(const mint a){return (*this)*=a.inv();}
    mint operator/(const mint a) const{return mint(*this)/=a;}
};
istream& operator>>(istream& is, mint& a) {return is>>a.x;}
ostream& operator<<(ostream& os, const mint& a) {return os<<a.x;}

struct combination{
    vector<mint> fact,ifact;
    combination(int n):fact(n+1),ifact(n+1){
        assert(n<mod);
        fact[0]=1;
        for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i;
        ifact[n]=fact[n].inv();
        for(int i=n;i>=1;i--) ifact[i-1]=ifact[i]*i;
    }
    mint operator()(int n,int k){
        if (k<0 || k>n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> a(n),sum(n+1,0);
    rep(i,n){
        cin>>a[i];
        sum[i+1]=sum[i]+a[i];
    }
    mint ans=0;
    rep(i,n){
        ans+=mint(a[i])*mint((sum[n]-sum[i+1]));
    }
    cout<<ans<<endl;
}