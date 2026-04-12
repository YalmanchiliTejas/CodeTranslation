#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
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
    mint pow(ll n)const{
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
mint dp[3005];
bool used[3005];
int main(){
 int n,m;
 cin>>n>>m;
 V<ll> a(n);
 for(int i=0;i<n;i++)cin>>a[i];
 used[0]=true;
 mint ans=0;
 for(int i=0;i<n;i++){
     dp[0]+=1;
     for(int j=m;j>=0;j--){
           if(used[j]&&a[i]+j<=m){
               dp[a[i]+j]+=dp[j];
               used[a[i]+j]=true;
           }
         }
     ans+=dp[m];
 }
 cout<<ans<<"\n";
}
