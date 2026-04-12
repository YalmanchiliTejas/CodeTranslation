#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define pll pair<ll,ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i,l,r) for(ll i = (l); i <= (ll)(r); i++)
#define rep3(i,l,r) for(ll i = (l); i >= (ll)(r); i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int inf = 1001001001;
const ll INF = 1LL << 60;
const ll mod = 1000000007;
const ld pi = acos(-1);
 
// union by size + path having
class UnionFind {
public:
   vector <ll> par; // 各元の親を表す配列
   vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
 
   // Constructor
   UnionFind(ll sz_): par(sz_),siz(sz_, 1LL){
       for (ll i=0; i<sz_; i++) par[i]=i; // 初期では親は自分自身
   }
   void init(ll sz_){
       par.resize(sz_);
       siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
       for (ll i=0; i<sz_; i++) par[i]=i; // 初期では親は自分自身
  }
 
   // Member Function
   // Find
   ll root(ll x){ // 根の検索
      while (par[x]!=x){
           x=par[x]=par[par[x]]; // x の親の親を x の親とする
       }
       return x;
  }
 
   // Union(Unite, Merge)
   bool unite(ll x, ll y){
       x=root(x);
       y=root(y);
       if (x==y) return false;
       // merge technique（データ構造をマージするテク．小を大にくっつける)
       if (siz[x]<siz[y]) swap(x, y);
       siz[x]+=siz[y];
       par[y]=x;
       return true;
  }
 
  bool same(ll x, ll y){ // 連結判定
       return root(x)==root(y);
  }
 
  ll size(ll x){ // 素集合のサイズ
      return siz[root(x)];
  }
};
 
ll modpow(ll x, ll n){
   x=x%mod;
   if(n==0) return 1;  //再帰の終了条件
 
   else if(n%2==1){
       return (x*modpow(x, n-1))%mod;  //nが奇数ならnを1ずらす
   }
   else return modpow((x*x)%mod, n/2)%mod;  //nが偶数ならnが半分になる
}
 
ll com(ll n, ll k){
   ll x=1;
   for(int i=n-k+1; i<=n; i++){
      x=x*i%mod;
   }
 
   ll y=1;
   for(int i=1; i<=k; i++){
       y=y*i%mod;
   }
   y=modpow(y, mod-2);
 
   return x*y%mod;
}
 
bool is_prime(const unsigned n){
   switch(n){
       case 0: // fall-through
       case 1: return false;
       case 2: // fall-through
       case 3: return true;
  } // n>3 が保証された
 
   if(n%2==0 || n%3==0) return false;
   // nは2と3のいずれの倍数でもないことが保証された
   // これよりnは(6の倍数)-1か(6の倍数)+1である
 
   // 6の倍数前後の数を使って試し割りをする
   for(unsigned i = 5; i*i<=n; i+=6) {
       if(n%i==0) return false; // (6の倍数)-1
       if(n%(i+2)==0) return false; // (6の倍数)+1
   }
 
   return true;
}
 
int digsum(int n){
   int res=0;
   while(n > 0) {
       res+=n%10; //ここをres++;に変えたら桁数を求める関数になる,res+=n%10;なら格桁の和
       n/=10;
   }
   return res;
}
vector<ll> divisor(ll n){
   vector<ll> ret;
   for(ll i=1; i*i<=n; i++){
       if(n%i==0){
           ret.push_back(i);
           if(i*i!=n) ret.push_back(n/i);
       }
   }
   sort(ret.begin(),ret.end());
   return ret;
}
 
int main(){

    ll n,ans=1,mmm;
    cin >> n;
    vector<ll> data(n);
    rep(i,n) cin >> data[i];
    rep(i,n){
        if(i==0){
            mmm=data[i];
            continue;
        }
        else if(data[i]>=mmm){
            chmax(mmm,data[i]);
            ans++;
            continue;
        }
    }

    cout << ans << endl;
 
}