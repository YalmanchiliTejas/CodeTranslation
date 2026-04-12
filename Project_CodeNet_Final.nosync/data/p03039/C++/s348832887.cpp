#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
struct mint{
    using ull=unsigned long long int;
    ull v;
    mint(ll vv=0){s(vv%mod+mod);}
    mint& s(ull vv){
        v=vv<mod?vv:vv-mod;
        return *this;
    }
    //オーバーロード
    mint operator-()const{return mint()-*this;}//符号反転
    mint&operator+=(const mint&val){return s(v+val.v);}
    mint&operator-=(const mint&val){return s(v+mod-val.v);}
    mint&operator*=(const mint&val){
        v=ull(v)*val.v%mod;
        return *this;
    }
    mint&operator/=(const mint&val){return *this*=val.inv();}
    mint operator+(const mint&val){return mint(*this)+=val;}
    mint operator-(const mint&val){return mint(*this)-=val;}
    mint operator*(const mint&val){return mint(*this)*=val;}
    mint operator/(const mint&val){return mint(*this)/=val;}
    mint pow(int n)const{
        mint res(1),x(*this);
        while(n){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }
    mint inv()const{return pow(mod-2);}
    //拡張ユークリッドの互除法
    /* mint inv()const{
        int x,y;
        int g=extgcd(v,mod,x,y);
        assert(g==1);
        if(x<0)x+=mod;
        return mint(x);
    }*/
    friend ostream& operator<<(ostream&os,const mint&val){
        return os<<val.v;
    }//出力
    bool operator<(const mint&val)const{return v<val.v;}
    bool operator==(const mint&val)const{return v==val.v;}
    bool operator>(const mint&val)const{return v>val.v;}
};
const ll MAX = 2000010;//設定
mint fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void init(){
    fac[0] = fac[1] = 1;
    for(int i=1;i<MAX;i++)fac[i]=fac[i-1]*i;
    finv[MAX-1]=fac[MAX-1].inv();
    for(int i=MAX-2;i>=0;i--)finv[i]=finv[i+1]*(i+1);
    for(int i=MAX-2;i>=1;i--)inv[i]=finv[i]+fac[i-1];
}
//階乗
mint factor(ll n,ll k){
  if (n<k) return 0;
  if (n<0 || k<0) return 0;
  return fac[n]*finv[k];
}
// 二項係数計算
mint COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}
int main(){
ll n,m,k;
cin>>n>>m>>k;
mint ans=0;
init();
for(int i=1;i<n;i++){
    ans+=mint(i)*mint(n-i)*mint(m*m)*COM(n*m-2,k-2);
}
for(int i=1;i<m;i++){
    ans+=mint(i)*mint(m-i)*mint(n*n)*COM(n*m-2,k-2);
}
cout<<ans<<endl;
}