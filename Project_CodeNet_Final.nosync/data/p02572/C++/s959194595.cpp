#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define _dec(i,N,j) for(int i = (N-1);i >= (j);i--)
#define _rec(i,N,j) for(int i = (N);i >=(j);i--)
#define ALL(x) x.begin(),x.end()
#define MEM(a,n) memset(a,n,sizeof(a))
#define fst first
#define scd second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int get_int(){int x;scanf("%d",&x);return x;}
LL get_ll(){LL x;scanf("%lld",&x);return x;}
double get_db(){double x;scanf("%lf",&x);return x;}

template<typename T> int chmin(T &a,T b){if(a > b){a = b;return 1;}else return 0;}
template<typename T> int chmax(T &a,T b){if(a < b){a = b;return 1;}else return 0;}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {_for(i,0,v.size()) os << v[i] << " ";return os;}
template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){for(auto a:v) os << a <<" ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& v){os << v.fst <<" "<<v.scd << " ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const map<T1,T2>& v){for(auto a:v) cout << a << endl;return os;}

static const int dx[8] = { -1,  0, 1, 0,  1, -1,  1, -1};
static const int dy[8] = {0,  1, 0,  -1,  1, -1, -1,  1};
const double pi  = acos(-1.0);
const double eps = 1e-8;
const LL  INF  = 0x3f3f3f3f3f3f3f3f;
const int inf  = 0x3f3f3f3f;

template <int mod>
struct mint{
  int x;
  constexpr mint() : x(0) {}
  constexpr mint(LL y): x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  constexpr mint &operator+=(const mint &p){if((x += p.x) >= mod) x -= mod;return *this;}
  constexpr mint &operator-=(const mint &p){if((x += mod - p.x) >= mod) x -= mod;return *this;}
  constexpr mint &operator*=(const mint &p) noexcept {x = (int)(1LL * x * p.x % mod);return *this;}
  constexpr mint &operator/=(const mint &p) noexcept {*this *= p.inv();return *this;}
  constexpr mint operator-() const {return mint(-x);}
  constexpr mint operator+(const mint &p) const{return mint(*this) += p;}
  constexpr mint operator-(const mint &p) const{return mint(*this) -= p;}
  constexpr mint operator*(const mint &p) const{return mint(*this) *= p;}
  constexpr mint operator/(const mint &p) const{return mint(*this) /= p;}
  constexpr bool operator==(const mint &p) const{return x == p.x;}
  constexpr bool operator!=(const mint &p) const{return x != p.x;}
  constexpr bool operator <(const mint &p) const{return x < p.x;}
  constexpr bool operator >(const mint &p) const{return x > p.x;}
  constexpr mint inv() const { return this->power(mod - 2);}
  constexpr mint operator^(LL n) const { return mint(this->power(n)); }
  constexpr mint &operator^=(LL n) { return *this = *this ^ n; }
  constexpr int get_mod() { return mod;}
  constexpr mint power(LL n) const {
    mint res(1), mul(x);
    while(n) {
        if(n & 1)
        res *= mul;
        mul *= mul;
    n >>= 1;
    }
    return res;
  }
   inline mint fac() const {
        static std::vector<mint> facs;
        int l0 = facs.size();
        if (l0 > this->x) return facs[this->x];
        facs.resize(this->x + 1);
        for (int i = l0; i <= this->x; i++) facs[i] = (i == 0 ? mint(1) : facs[i - 1] * mint(i));
        return facs[this->x];
    }
    mint nCr(const mint &r) const {
        if (this->x < r.x) return mint(0);
        return this->fac() / ((*this - r).fac() * r.fac());
  }
  friend constexpr ostream &operator<<(ostream &os, const mint &p){return os << p.x;}
  friend constexpr istream &operator>>(istream &is,mint &a){LL t = 0;is >> t;a = mint<mod>(t);return (is);}
};
constexpr LL MOD = 1e9+7;
using mi = mint<MOD>;
const int maxn = 2e5+5;

mi A[maxn];

int main()
{
    LL N;
    cin >> N;

    mi res(0);
    mi sum(0);
    _for(i,0,N){
        cin >> A[i];
        sum = sum + A[i];
    }

    _for(i,0,N){
        res = res + (sum - A[i])*A[i];
    }

    res = res/2;

    cout << res << endl;


    return 0;
}
