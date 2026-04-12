#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <numeric>
#define IINF 1000000000
#define INF 3223372036854775807
#define MOD 1000000007
#define mod 1000000007
#define INT_MAX_ 2147483647
#define EPS (1e-10)
#define REP(i, a, n) fo-r (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
//#define rep(i,n)for (ll i = 0; i < (ll)(n); i++)
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
#define me memset
#define bit(n,k) ((n>>k)&1)
#define lg length()
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int>Pin;
typedef pair<ll,ll>Pll;
template<class T> using V=vector<T>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define invp(a,p)pom(a,p-2,p)
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp1(pair<Pll,ll> a,pair<Pll,ll> b){
        return a.fi.se>b.fi.se;
}
ll cmp2(pair<ll,ll> a,pair<ll,ll> b){
    if(a.se!=b.se)
        return a.se<b.se;
    else
        return a.fi<b.fi;
}
//----------------------------------------------------------------------
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
ll modpow(ll a, ll n) {//a^n(MOD)を求める
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;//次の準備
        n >>= 1;
    }
    return res;
}
ll waru(ll a,ll b){
    return a*modpow(b,mod-2)%mod;
}

ll permutation(ll n,ll r)
{
    ll a=1;
    for(ll i=n-r+1;i<=n;i++)
        a*=i;
    return a;
}

ll nCr(ll n, ll r) {
    ll ans = 1;
    for (ll i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (ll i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}
//----------------------------------------------------------------------
int main(int argc, char * argv[]){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_t=clock();
    //freopen("big.txt", "r", stdin);
    //freopen("out3.txt", "w", stdout);
    //------------------------------
    ll n;cin>>n;
    V<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll sum[200020];
    sum[n-1]=a[n-1];
    for(ll i=n-2;i>=0;i--){
        sum[i]=sum[i+1]+a[i];
    }
    mint ans=0;
    for(ll i=0;i<n-1;i++){
        if(a[i]==0)ans+=0;
        else ans+=a[i]*(sum[i+1]%mod);
    }
    cout<<ans<<endl;
    //------------------------------
    //fclose(stdin);
    //fclose(stdout);
    //ll end_t=clock();cout<<"time="<<end_t-begin_t<<"ms"<<endl;
    //------------------------------- 
    return 0;
}
//----------------------------------------------------------------------








































