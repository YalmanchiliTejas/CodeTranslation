#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using Graph = vector<vector<edge>>;
using dou =long double;
string yes="yes";
string Yes="Yes";
string YES="YES";
string no="no";
string No="No";
string NO="NO";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
//const ll mod = 998244353;
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
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}




#define rep(i, n)         for(ll i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto &i : container)
#define itrep(i,container) for (auto i : container)
#define irep(i, n)        for(ll i = n-1; i >= (ll)0ll; i--)
#define rrep(i,m,n) for(ll i = m; i < (ll)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define query int qq;std::cin >> qq;rep(qqq,qq)
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum(a) accumulate(all(a),0ll)
#define keta fixed<<setprecision
#define vout(a) erep(qxqxqx,a)std::cout << qxqxqx << ' ';std::cout  << std::endl;
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
//#define vvector(name,typ,m,n)vector<vector<typ> > name(m,vector<typ> (n))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
#define case std::cout <<"Case #" <<qqq+1<<": "
#define res resize
#define as assign
#define ffor for(;;)
#define ppri(a,b) std::cout << a<<" "<<b << std::endl
#define pppri(a,b,c) std::cout << a<<" "<<b <<" "<< c<<std::endl
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define ssum(a) accumulate(a,0ll) 
//#define grid_input(a,type) int h,w;std::cin >> h>>w;vvector(a,type,h,w,0);reprep(i,j,h,w)std::cin >> a[i][j];

//typedef long long T;
ll ceil(ll a,ll b){
    return ((a+b-1)/b);
}
const int INF = 2000000000;
const ll INF64 =3223372036854775807ll;
//const ll INF64 = 9223372036854775807ll;
//const ll INF64 = 9223372036854775ll;
const ll MOD = 1000000007ll;
const dou pi=3.141592653589793;

//メモ
//tuple<hoge,huga,foo> tのget関数はget<i>(t)
//resizeはメンバ関数
//三項演算子を覚えよう
// a?b:cと書くと aならばbの処理をする
ll x;
ll ans=0;
std::vector<ll> a,b;
void solve(int n){
    if(x==0)return;
    if(x>=a[n]){
        x-=a[n];
        ans+=b[n];
        return;
    }
    if(n==0){
        x--;
        return;
    }
    
    x--;
    if(x==0)return;
    solve(n-1);
    if(x==0)return;
    x--;ans++;
    if(x==0)return;
    solve(n-1);
    if(x==0)return;
    x--;
    return;
}
int main(){
    ll n;
    std::cin >> n>>x;
    a.resize(n+1);
    b.resize(n+1);
    a[0]=1;b[0]=1;
    rep(i,n)a[i+1]=3+2*a[i];
    rep(i,n)b[i+1]=1+2*b[i];
    solve(n);
    std::cout << ans << std::endl;
}