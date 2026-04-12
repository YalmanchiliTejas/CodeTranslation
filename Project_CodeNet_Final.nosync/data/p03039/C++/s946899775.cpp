#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REPR(i,n) for (int i=(int)(n)-1;i>=0;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
#define tpl(...) make_tuple(__VA_ARGS__)
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1);
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
typedef long long ll;
typedef pair<int,int> pii;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename Ch,typename Tr,typename C,typename=decltype(begin(C()))>basic_ostream<Ch,Tr>& operator<<(basic_ostream<Ch,Tr>&os,
const C& c){os<<'[';for(auto i=begin(c);i!=end(c);++i)os<<(i==begin(c)?"":" ")<<*i;return os<<']';}
template<class S,class T>ostream&operator<<(ostream &o,const pair<S,T>&t){return o<<'('<<t.first<<','<<t.second<<')';}
template<int N,class Tp>void output(ostream&,const Tp&){}
template<int N,class Tp,class,class ...Ts>void output(ostream &o,const Tp&t){if(N)o<<',';o<<get<N>(t);output<N+1,Tp,Ts...>(o,t);}
template<class ...Ts>ostream&operator<<(ostream&o,const tuple<Ts...>&t){o<<'(';output<0,tuple<Ts...>,Ts...>(o,t);return o<<')';}
template<class T>void output(T t,char z=10){if(t<0)t=-t,putchar(45);int c[20];
int k=0;while(t)c[k++]=t%10,t/=10;for(k||(c[k++]=0);k;)putchar(c[--k]^48);putchar(z);}
template<class T>void outputs(T t){output(t);}
template<class S,class ...T>void outputs(S a,T...t){output(a,32);outputs(t...);}
template<class T>void output(T *a,int n){REP(i,n)cout<<a[i]<<(i!=n-1?',':'\n');}
template<class T>void output(T *a,int n,int m){REP(i,n)output(a[i],m);}
template<class T>bool input(T &t){int n=1,c;for(t=0;!isdigit(c=getchar())&&~c&&c-45;);
if(!~c)return 0;for(c-45&&(n=0,t=c^48);isdigit(c=getchar());)t=10*t+c-48;t=n?-t:t;return 1;}
template<class S,class ...T>bool input(S&a,T&...t){input(a);return input(t...);}
template<class T>bool inputs(T *a, int n) { REP(i,n) if(!input(a[i])) return 0; return 1;}

template<int MOD>
struct ModInt {
  int x;
  constexpr ModInt() : x(0) {}
  ModInt(ll s) { if ((x = s % MOD) < 0) x += MOD; }
  ModInt operator+=(ModInt rhs) { if ((x+=rhs.x) >= MOD) x -= MOD; return *this; }
  ModInt operator-=(ModInt rhs) { if ((x-=rhs.x) < 0) x += MOD; return *this; }
  ModInt operator*=(ModInt rhs) { x = (ll)x*rhs.x % MOD; return *this; }
  ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/=(ModInt rhs) {
    static const ll inv2 = ModInt(2).inv().x; // 2で割るのは特別に保存してみる
    ll i = (rhs.x == 2 ? inv2 : rhs.inv().x);
    x = x*i%MOD; return *this;
  }
  ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
  ModInt inv() { return pow(MOD-2); }
  ModInt pow(ll n) const {
    ModInt r = 1, t = x;
    for (;n;n>>=1,t*=t) if (n&1) r *= t;
    return r;
  }
  static ModInt strnum(const string &n) {ModInt a = 0; for (char c:n) a = a*10+c-'0'; return a;}
  friend ostream& operator<<(ostream &os, const ModInt rhs){ return os << rhs.x; }
};
typedef ModInt<int(1e9+7)> mint;

ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll g = a;
  x = 1; y = 0;
  if (b) {
    g = extgcd(b, a%b, y, x);
    y -= (a/b) * x;
  }
  return g;
}

ll invMod(ll a, ll p) {
  ll x, y;
  if (extgcd(a,p,x,y) == 1) return (x+p)%p;
  return 0;
}

struct ModFact {
  int maxn;
  ll p;
  vector<ll> fact;
  ModFact(int maxn, ll p) : maxn(maxn), p(p), fact(maxn+1) {
    fact[0] = 1;
    REP(i, maxn)
      fact[i+1] = fact[i] * (i+1) % p;
  }
  int combi(int n, int k) {
    if (n<0||k<0||n<k) return 0;
    assert(n <= maxn);
    return fact[n] * invMod(fact[k]*fact[n-k]%p, p) % p;
  }
  int perm(int n, int k) {
    if (n<0||k<0||n<k) return 0;
    assert(n <= maxn);
    return fact[n] * invMod(fact[n-k],p) % p;
  }
};

ModFact mf(200005, 1e9+7);

int main() {
  int n, m, k;
  while(input(n,m,k)) {
    // for (int i = 1; i <= (n-1) + (m-1); i++) {

    // }
    // mint ans;
    mint c = mf.combi(n*m-2,k-2);
    // REP(i,n) {
    //   REP(j,m) {
    //     for(int i2=i;i2<n;i2++) {
    //       for(int j2=0; j2<m; j2++) {
    //         if (i == i2 && j <= j2) continue;
    //         ans += mint(abs(i-i2) + abs(j-j2));
    //       }
    //     }
    //   }
    // }
    mint ans = 0; //mint(mf.combi(n,2)) * m * m + mint(mf.combi(m,2)) * n * n;

    for (int i=1; i<n; i++) {
      ans += mint(i) * (n - i) * m * m;
    }
    for (int i=1; i<m; i++) {
      ans += mint(i) * (m - i) * n * n;
    }

    cout << ans * c << endl;
  }
}
