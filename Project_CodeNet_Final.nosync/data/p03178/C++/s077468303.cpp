#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;
const ll mod=1e9+7;

template<typename T> T npow(T x, ll n){
    T ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x;
        x = x*x;
        n = n >> 1;
    }
    return ans;
}

class mint {
 private:
  ll _num,_mod;
  mint set(ll num){ 
      _num = num ;
      if(_num<0){
          if(_num>=-mod)_num=mod+_num;
          else _num=mod-llabs(_num)%mod;
      }
      else if(_num>=mod) _num%=mod;
      return *this;
  }
  ll _mpow(ll x, ll n){
    ll ans = 1;
    if(x>=mod) x%=mod;
    while(n != 0){
        if(n&1) ans = ans*x % _mod;
        x = x*x % _mod;
        n = n >> 1;
    }
    return ans;
  }
  ll imod(ll n){return _mpow(n , _mod-2);}
 public:
  mint(){ _num = 0;_mod=mod; }
  mint(ll num){
      _mod = mod; 
      _num = num;
      if(_num<0){
          if(_num>=-mod)_num=mod+_num;
          else _num=mod-llabs(_num)%mod;
      }
      else if(_num>=mod) _num%=mod;
  }
  mint(ll num,ll M){
      _mod=M;
      _num=num;
      if(_num<0){
          if(_num>=-mod)_num=mod+_num;
          else _num=mod-llabs(_num)%mod;
      }
      else if(_num>=mod) _num%=mod;
  }
  mint(const mint &cp){_num=cp._num;_mod=cp._mod;}
  mint operator+ (const mint &x){ return mint(_num + x._num , _mod); }
  mint operator- (const mint &x){ return mint(_num - x._num , _mod);}
  mint operator* (const mint &x){ return mint(_num * x._num , _mod); }
  mint operator/ (mint x){ return mint(_num * imod(x._num) , _mod);}
  
  mint operator+=(const mint &x){ return set(_num + x._num); }
  mint operator-=(const mint &x){ return set(_num - x._num); }
  mint operator*=(const mint &x){ return set(_num * x._num); }
  mint operator/=(mint x){ return set(_num * imod(x._num));}

  mint operator= (const ll x){ return set(x); }
  mint operator+ (const ll x){return *this + mint(x,_mod); }
  mint operator- (const ll x){ return *this - mint(x,_mod); }
  mint operator* (const ll x){ return *this * mint(x,_mod); }
  mint operator/ (ll x){ return *this/mint(x);}

  mint operator+=(const ll x){ return set(_num + x); }
  mint operator-=(const ll x){ return set(_num - x); }
  mint operator*=(const ll x){ return set(_num * (x % _mod)); }
  mint operator/=(ll x){ return set(_num * imod(x));}

  bool operator<(const mint &x)const{return _num<x._num;}
  bool operator==(const mint &x)const{return _num==x._num;}
  bool operator>(const mint &x)const{return _num>x._num;}

  friend mint operator+(ll x,const mint &m){return mint(m._num + x , m._mod);}
  friend mint operator-(ll x,const mint &m){return mint( x - m._num , m._mod);}
  friend mint operator*(ll x,const mint &m){return mint(m._num * (x % m._mod) , m._mod);}
  friend mint operator/(ll x,mint m){return mint(m.imod(m._num) * (x % m._mod) , m._mod);}

  explicit operator ll() { return _num; }
  explicit operator int() { return (int)_num; }

  friend ostream& operator<<(ostream &os, const mint &x){ os << x._num; return os; }
  friend istream& operator>>(istream &is, mint &x){ll val; is>>val; x.set(val); return is;}
};

int main(){
    typedef vector<mint> vi;
    typedef vector<vi> vvi;
    typedef vector<vvi> vvvi;
    string K;cin>>K;
    int D;cin>>D;
    int N=K.size();
    vvvi dp(N+1,vvi(D,vi(2,0)));
    dp[0][0][1]=1;
    REP(i,K.size()) REP(j,D){
        REP(k,10){
            dp[i+1][(j+k)%D][0]+=dp[i][j][0];
            if(k<K[i]-'0') dp[i+1][(j+k)%D][0]+=dp[i][j][1];
            if(k==K[i]-'0') dp[i+1][(j+k)%D][1]+=dp[i][j][1];
        }
    }
    cout<<(dp[N][0][0]+dp[N][0][1]+mod-1)<<endl;
}
