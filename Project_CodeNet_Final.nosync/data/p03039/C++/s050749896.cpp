#include <bits/stdc++.h>

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;
 
public:
  u64 a;
 
  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define doublecout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second
#define P pair<ll,ll> 
#define m_p make_pair
#define V vector<ll> 
#define U_MAP unordered_map<ll,ll>

ll n,cnt,a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k,f[ohara],fr[ohara];
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
        cin.tie(0);
        cout.tie(0);
    ios::sync_with_stdio(false);

    using mint=modint<MOD>;

    cin>>n>>m>>k;

    vector<mint> fa(ohara);
    fa[0]=1;
    rrep(i,1,ohara){
    fa[i]=fa[i-1]*i;
    }
    const auto comb = [&fa](int n,int r) {
        return fa[n]/fa[r]/fa[n-r];
    };

    mint ans1=0;
    rrep(sa,1,m){
        mint cost;
        cost=(m-sa)*n*n;
        ans1+=mint(sa)*cost.value()*comb(n*m-2,k-2);
    }

    mint ans2=0;
    rrep(sa,1,n){
        mint cost;
        cost=(n-sa)*m*m;
        ans2+=mint(sa)*cost.value()*comb(n*m-2,k-2);
    }

    mint ans;
    ans=ans1.value()+ans2.value();
    Cout(ans.value());
    return 0;
}
