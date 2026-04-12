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

template<ll Mod>
struct ModInt{
    long long x;
    ModInt():x(0){}
    ModInt(long long y):x(y>=0?y%Mod:(Mod-(-y)%Mod)%Mod){}
    ModInt &operator+=(const ModInt &p){
        if((x+=p.x)>=Mod) x-=Mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p){
        if((x+=Mod-p.x)>=Mod)x-=Mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p){
        x=(int)(1ll*x*p.x%Mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p){
        (*this)*=p.inverse();
        return *this;
    }
    ModInt operator-()const{return ModInt(x);}
    ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}
    ModInt operator-(const ModInt &p)const{return ModInt(*this)-=p;}
    ModInt operator*(const ModInt &p)const{return ModInt(*this)*=p;}
    ModInt operator/(const ModInt &p)const{return ModInt(*this)/=p;}
    ModInt operator==(const ModInt &p)const{return x==p.x;}
    ModInt operator!=(const ModInt &p)const{return x!=p.x;}
    ModInt inverse()const{
        int a=x,b=Mod,u=1,v=0,t;
        while(b>0){
            t=a/b;
            swap(a-=t*b,b);swap(u-=t*v,v);
        }
        return ModInt(u);
    }
    ModInt pow(long long n)const{
        ModInt ret(1),mul(x);
        while(n>0){
            if(n&1) ret*=mul;
            mul*=mul;n>>=1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os,const ModInt &p){return os<<p.x;}
    friend istream &operator>>(istream &is,ModInt &a){long long t;is>>t;a=ModInt<Mod>(t);return (is);}
    static int get_mod(){return Mod;}
};
using mint=ModInt<mod>;
 
template<int MAX>
struct comcalc{
    vector<mint> fact,finv,inv;
    comcalc():fact(MAX),finv(MAX),inv(MAX){
        fact[0]=mint(1),fact[1]=mint(1),finv[0]=mint(1),finv[1]=mint(1),inv[1]=mint(1);
        for(int i=2;i<MAX;i++){
            fact[i]=fact[i-1]*mint(i);
            inv[i]=mint(0)-inv[mod%i]*(mint(mod/i));
            finv[i]=finv[i-1]*inv[i];
        }
    }
    mint com(int n,int k){
        if(n<k) return mint(0);
        if(n<0 or k<0) return mint(0);
        return fact[n]*(finv[k]*finv[n-k]);
    }
    mint fac(int n){
        return fact[n];
    }
    // 重複組み合わせ:n種類の物から重複を許し，k個選ぶ
    mint nHk(int n,int k){
        return com(n+k-1,k);
    }
    // 玉n区別，箱k区別，各箱1個以上O(k)
    mint F12_dis_dis_one(int n,int k){
        if(n<k)return mint(0);
        mint ret=0;
        for(int i=0;i<=k;i++){
            mint add=com(k,i)*(mint(i).pow(n));
            if((k-i)%2) ret-=add;
            else        ret+=add;
        }
        return ret;
    }
};
mint pow_mod(mint x,ll n){
    return x.pow(n);
}
mint inv_mod(mint x){
    return x.inverse();
}
// O(n)
mint fact_mod(ll n){
    mint ret=1;
    for(int i=2;i<=n;i++) ret*=mint(i);
    return ret;
}
// O(r)
mint comb_mod(ll n,ll r){
    if(r>n-r) r=n-r;
    if(r==0) return 1;
    mint a=1,b=mint(fact_mod(r)).inverse();
    for(int i=0;i<r;i++)a*=mint(n-i);
    return a*b;
}
 
const int MAX=4010000;
using cominit=comcalc<MAX>;



signed main(){
    int n;cin>>n;
    vector<mint> a(n);
    cin>>a;
    mint res=0;
    mint sum=0;
    rep(i,n)sum+=a[i];
    rep(i,n)res+=a[i]*sum;
    rep(i,n)res-=a[i]*a[i];
    res/=mint(2);
    cout<<res<<endl;
    return 0;
}
