#include <bits/stdc++.h>

// #define fi first
// #define se second
#define rep(i, n) for (ll i=0;i<(n); i++)
#define ALL(v) (v).begin(), (v).end()
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

const ll M=1000000007ll;
const ll MOD=1000000007ll;
const ll MAX=100000001ll;
//const ll M = 1000000000+7;

const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

mint f(ll n){
  if(n==0) return 1;
  mint ans = f(n/2);
  ans *= ans;
  if(n%2==1) ans*= 2;
  return ans;
}

mint choose(ll n, ll k){
  mint x=1, y=1;
  rep(i,k){
    x *= (n-i);
    y *= (i+1);
  }
  return x / y;
}

struct BIT {
  private:
   vector<ll> bit;
   ll N;
 
  public:
   BIT(ll size) {
     N = size;
     bit.resize(N + 1);
   }
 
   // 一点更新です
   void add(ll a, ll w) {
     for (ll x = a; x <= N; x += x & -x) bit[x] += w;
   }
 
   // 1~Nまでの和を求める。
   int sum(ll a) {
     ll ret = 0;
     for (ll x = a; x > 0; x -= x & -x) ret += bit[x];
     return ret;
   }
 };
 
ll fff(ll n, vector<ll>& v, ll i, ll j, ll rl){
  ll can = 0;
  ll can_i = 0;

  cout << v[0]<<endl;
  
  // right
  if(rl == 0){
    rep(k, n){
      if(v[k]*(j-k)>can){
	can = v[k]*(j-k);
	can_i = k;
      }
      //cout << can<<endl;
    }
    v[can_i] = 0;
    return can;
  }
  // left
  else{
    rep(k, n){
      if(v[k]*(k-i)>can){
	can = v[k]*(k-i);
	can_i = k;
      }
      //cout << can<<endl;

    }
    v[can_i] = 0;
    return can;
  }
  
}


int main(){
  ll h,w;

  cin>>h>>w;

  ll i = 0;
  string tmp;

  string white = "";
  rep(i, w){
    white += ".";
  }

  vector<string> v;
  
  while(i<h){
    cin>>tmp;
    if(tmp==white){
      h--;
      continue;
    }
    v.push_back(tmp);
    i++;
  }

  vector<ll> ok(w, 0);
  rep(j, w){
    rep(k, h){
      if(v[k][j]=='#') {
	ok[j] = 1;
	break;
      }
      //cout << j << " "<<k<<endl; 
    }
  }

  // rep(j,w){
  //   cout << ok[j]<<endl;
  // }
  
  rep(k, h){
    rep(j, w){
      if(ok[j]) cout << v[k][j];
    }
    cout <<endl;
  }

  // cout << v[0]<<endl;
  // cout << v[1]<<endl;
  //cout<<tmp<<endl;
}
