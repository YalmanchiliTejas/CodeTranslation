#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){cout << (v[i]) << " ";} cout << endl;
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

template<class T>
using MaxHeap = std::priority_queue<T>;

template<class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}

template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}

int pop_count(int n){
  return __builtin_popcount(n);
}

int pop_count(ll n){
  return __builtin_popcountll(n);
}

ll gcd(ll a, ll b) {
    if(a < b) swap(a,b);
    
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a,b);
    return (a/g)*b;
}

// 素数判定 O(√n)
bool is_prime(ll n){
    if(n == 1) return false;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

// 約数列挙 O(√n)
vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

template<typename T>
map<T, ll> prime_factorize(T x){
  map<T, ll> res;
  for(int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}

// エラトステネスの篩
// return lp[i] := iの最小素因数(lp[i] == iならば素数)
vector<int> SieveOfEratosthenes(int N = 10000000){
  vector<int> lp(N + 1, 0);
  vector<int> pr;
  for (int i=2; i<=N; ++i) {
      if (lp[i] == 0) {
          lp[i] = i;
          pr.push_back(i);
      }
      for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
          lp[i * pr[j]] = pr[j];
  }
  return lp;
}


// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x(x%mod){}
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

const int MOD = 1000000007;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;

ll intceil(ll a, ll b){
    if(a < 0){
      a *= -1;
      b *= -1;
    }
    if(b >= 0) return (a + b - 1 ) / b;
    return a / b;
}

ll intfloor(ll a, ll b){
    if(a < 0){
      a *= -1;
      b *= -1;
    }
    if(b >= 0) return a / b;
    return (a - b + 1) / b;
}

void addM(ll &a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mulM(ll &a, ll b) {
    a = ((a%MOD)*(b%MOD))%MOD ;
}

ll powM(ll a,ll b) {
    ll ret = 1;
    ll tmp = a;
    while(b>0) {
        if((b&1)==1) ret = (ret * tmp) % MOD;
        tmp = (tmp * tmp) % MOD;
        b = b >> 1;
    }
    return ret;
}

// mod. m での a の逆元 a^{-1} を計算する
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// ラングレンス圧縮
vector<pair<char, int>> rang_com(string s){
  vector<pair<char, int>> ret;
  string t = s;
  t.erase(unique(all(t)), t.end());
  int now = 0;
  int pre = 0;
  for(auto ct : t){
    while(now < s.size() && s[now] == ct) now++;
    if(ret.size() == 0){
      ret.push_back({ct, now});
    } else {
      ret.push_back({ct, now - pre});
    }
    pre = now;
  }
  return ret;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);  

  int N;
  cin >> N;

  vector<ll> a(N);
  REP(i, N) cin >> a[i];

  auto dp = make_vec<ll>(N+1, 4);
  fill_v(dp, -longinf);
  dp[0][0] = 0;

  int k = 1 + N%2;
  REP(i, N){
    REP(j, k+1){
      chmax(dp[i+1][j+1], dp[i][j]);
      ll now = dp[i][j];
      if((i+j)%2 == 0) now += a[i];
      chmax(dp[i+1][j], now);
    }
  }
  cout << dp[N][k] << endl;

  return 0;
}