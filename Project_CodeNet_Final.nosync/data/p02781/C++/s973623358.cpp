#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <map>

#define fir first
#define sec second
#define sz(s) (s).size()
#define pb push_back
#define get(n) scanf("%d",&n);
#define gets(s) string s;cin >> (s);
#define prfi(n) printf("%d", &n);
#define prfd(n) printf("%lf", &n);
#define All(s) (s).begin(), (s).end()
#define rep(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
#define rep0(i,j) for(int (i)=0;(i)<(j);(i)++)
#define repdown(i, j, k) for(int (i)=(j);(i)>=(k);(i)--)
#define repdown0(i,j) for(int (i)=(j);i>=0;i--)
#define vfor(c,v) for(auto (c): v)
#define dump(x)  std::cout << #x << " = " << (x) << std::endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using ll = long long;
using pii = std::pair<int,int>;
using vi = std::vector<int> ;
using vvi = std::vector<vi> ;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vd = std::vector<double> ;
using vvd = std::vector<vd> ;
using qi = std::queue<int> ;
using vpii = std::vector<std::pair<int, int> >;
using namespace std;

const int Mod = (1e9) + 7;
const int max_n = 3 * (1e5) + 1;
const int max_m = 83 * (1e5) + 1;
const int INF = 10241024;
const ll INFL = (1ll << 62) - 1;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

//_____________________________________Templates_________________________________________//

template<class T1, class T2> inline void chmin(T1 &a, T2 b){if(a > b) a = b;}
template<class T1, class T2> inline void chmax(T1 &a, T2 b){if(a < b) a = b;}

//mainly use for dynamic prog
template<class T1, class T2>
void update(T1 &a, T2 b){
  a += b;
  if(a > Mod) a %= Mod;
}

inline void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

inline void OUT(void){
  cout << "\n";
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

template<class T>
struct segt{
  
  int n;
  T def;
  vector<T> dat;
  function<T(T, T)> operation;
  function<T(T, T)> update;
  

  segt(size_t _n, T _def, 
    function<T(T, T)> _operation, function<T(T, T)> _update) : def(_def), operation(_operation), update(_update)
    {
      n = 1;
      while (n < _n){
        n *= 2;
      }
      dat = vector<T>(2*n - 1, _def);
    }

  T _query(int a, int b, int k, int l, int r){
    if(r <=a  || b <= l)return def;
    if(a <= r && l <= b)return dat[k];
    else
    {
      T vl = _query(a, b, k*2 + 1, l, (l+r)/2);
      T vr = _query(a, b, k*2 + 2, (l+r)/2, r);
      return operation(vl, vr);
    }
  }

  T query(int a, int b){
    return _query(a,b, 0, 0, n);
  }

  void change(int i, T value){
    i += n - 1;
    dat[i] = update(dat[i], value);
    while(i > 0){
      i = (i - 1) / 2;
      dat[i] = operation(dat[i*2 + 1], dat[i*2 + 2]);
    }
  }

  T operator[](int i){
    return dat[i + n - 1];
  }
};
//__________________MP method_________//
template<class T>
struct MP {
  int n;
  vi a;
  T t;
  MP(){}
  MP(const T &t) : t(t){
    n = sz(t);
    a = vi(n+1);
    a[0] = -1;
    int j = -1;
    rep(i,0,n-1){
      while(j != -1 && t[j] != t[i])j = a[j];
      j++;
      a[i+1] = j;
    }
  }
  int operator[] (int i){
    return a[i];
  }
  vi findAll(const T& s){
    vi res;
    int j = 0;
    rep(i,0,sz(s)-1){
      if(j != -1 && s[i] != t[j])j = a[j];
      j++;
      if(j == n){
        res.pb(i-j+1);
        j = a[j];
      }
    }
    return res;
  }
};
//________________________Mod int _______________________//
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%Mod+Mod)%Mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= Mod) x -= Mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += Mod-a.x) >= Mod) x -= Mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= Mod;
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
    return pow(Mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < Mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};
 

//_____________________array calc____________________________________//
/*
vvi mul(vvi &A, vvi &B){
  vvi C(A.size(), vi(B.size()))
  rep(i,A.size()){
    rep(j,B.size()){
      rep(k,B[0].size()){
        C[i][j] = (C[i][j] A[i][k] + B[k][j]) % Mod;
      }
    }
  }

  return C;
}

vvi pow(vvi A, ll n){
  vvi B(A.size(), vi(A.size()));
  rep(i=0;i<A.size();i++){
    B[i][i] = 1;
  }

  while (n >0){
    if (n & 1) B = mul(B, A);
    A = mul(A, A);
    n = n >> 1;
  }
  return B;
}
*/
//_____________________Bynary Indexed Tree __________________________//
/*
struct BIT{
  #define bs (1 << 20)
  int bit[bs];

  int sum (int i){
    int s = 0;
    while(i > 0){
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, int x){
    while(i <= n){
      bit[i] += x;
      i += i & -i;
    }
  }
}
*/

//____________________RMQ____________________________//
struct RMQ{
  #define s (1 << 20)
  ll dat[s];
  int n;

  void init(){
    memset(dat, -1e10, sizeof(dat));
  }

  void upd(int k, ll a){
    k += s/2 - 1;
    dat[k] = a;
    while(k > 0){
      k = (k -1) /2;
      dat[k] = max(dat[k*2+1], dat[k*2+2]);
    }
  }

  ll query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return -1e8;
    if( a <= l && r <= b)return dat[k];
    else 
    {
      ll vl = query(a, b, k*2+1, l, (l+r)/2);
      ll vr = query(a, b, k*2+2, (l+r)/2, r);
      return max(vl, vr);
    }
  }

  void Debug(int a){
    a += s/2 - 1;
    rep(i,s/2 - 1,a){
      dump(dat[i]);
    }
  }
};
//_____________________　following sorce code_________________________//
int n,m,k,x,y;
//vvll dp(400, vll(400));
int dp[110][5][2];
string S;
vvll v(16, vll(16));
vll cost(1 << 16);

int main () {
  cin.tie(0);
  ios::sync_with_stdio(false);
  memset(dp, 0, sizeof(dp));
  int K;
  IN(S);
  IN(K);
  int n = sz(S);
  dp[0][0][0] = 1;
  rep(i,0,n-1)rep(j,0,3)rep(k,0,1){
    int sx = S[i] - '0';
    rep(l,0,9){
      int  si = i+1, sj = j, sk = k;
      if(l != 0)sj++;
      if(sj > K)continue;
      if(k == 0)
      {
        if(l > sx)continue;
        if(l < sx)sk = 1;
      }
      dp[si][sj][sk] += dp[i][j][k];
    }
  }
  int ans = dp[n][K][0] + dp[n][K][1];
  OUT(ans);
  
  //cout << fixed << setprecision(15) << ans << endl;
  return 0;
}