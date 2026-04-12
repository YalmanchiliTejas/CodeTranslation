#include <bits/stdc++.h>


/*
#include <atcoder/all>
using namespace atcoder;
*/
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;


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
const ll mod = 998244353ll;
//const ll mod = 10000000000ll;
//const ll mod = 10000;

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
#define rep(i, n)         for(ll i = 0; i < (ll)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define bbrep(n)           for(int bbit=0;bbit<(1<<n);bbit++)
#define erep(i,container) for (auto &i : container)
#define itrep(i,container) for (auto i : container)
#define irep(i, n)        for(ll i = n-1; i >= (ll)0ll; i--)
#define rrep(i,m,n) for(ll i = m; i < (ll)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
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
//#define sum(a) accumulate(all(a),0ll)
#define keta fixed<<setprecision
#define vout(a) erep(qxqxqx,a)std::cout << qxqxqx << ' ';std::cout  << std::endl;
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
//#define vvector(name,typ,m,n)vector<vector<typ> > name(m,vector<typ> (n))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
#define case std::cout <<"Case #" <<qqq+1<<":"
#define RES(a,i,j) a.resize(i);rep(ii,i)a[ii].resize(j);
#define RESRES(a,i,j,k) a.resize(i);rep(ii,i)a[ii].resize(j);reprep(ii,jj,i,j){dp[ii][jj].resize(k)};
#define res resize
#define as assign
#define ffor for(;;)
#define ppri(a,b) std::cout << a<<" "<<b << std::endl
#define pppri(a,b,c) std::cout << a<<" "<<b <<" "<< c<<std::endl
#define ppppri(a,b,c,d) std::cout << a<<" "<<b <<" "<< c<<' '<<d<<std::endl
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define SUM(a) accumulate(all(a),0ll) 
#define stirng string
#define gin(a,b) int a,b;std::cin >> a>>b;a--;b--;
#define popcount __builtin_popcount
#define permu(a) next_permutation(all(a))
//#define grid_input(a,type) int h,w;std::cin >> h>>w;vvector(a,type,h,w,0);reprep(i,j,h,w)std::cin >> a[i][j];

//typedef long long T;
ll ceil(ll a,ll b){
    return ((a+b-1)/b);
}
const int INF = 2000000000;
//const ll INF64 =3223372036854775807ll;
//const ll INF64 = 9223372036854775807ll;
const ll INF64 = 243000000000000000;

const ll MOD = 998244353ll;
//const ll MOD = 1000003ll;
const ll OD = 1000000000000007ll;
const dou pi=3.141592653589793;
long long modpow(long long a, long long n) { //累乗の余剰
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}


//メモ
//ゲーム(Grundy数とか)の復習をする
//群論の勉強をする？
//学会のスライドを治す(木曜日まで)
//周期性の実験をする
//リスニング力をどうにかする
//マンハッタン距離の問題は45度回転するとうまくいくことがあるらしいよ！
//とりあえずALCはちゃんと埋める(遅延セグ木のやつわかんね～)
//特に理由がなければllを使おうキャンペーン
//
int main(){
    ll n,x,m;
    std::cin >> n>>x>>m;
    
    ll ans=x;
    //n;
    set<ll> al;
    set<PL> at;
    bool kuri=0;
    al.insert(x);
    at.insert(mp(x,0));
    ll cy=0;
    ll ni=0;
    rrep(i,1,n){
        //std::cout << x << std::endl;
        x=(x*x)%m;
        
        if(al.find(x)!=al.end()){
            kuri=1;
           // std::cout << x << std::endl;
            PL d=*at.lb(mp(x,-5));
          //  ppri(d.fi,d.se);
            cy=i-d.se;
            ni=i;
            break;
        }
        else{
            ans+=x;
            al.insert(x);
            at.insert(mp(x,i));
        }
        
    }
    if(!kuri){
        //std::cout << 123 << std::endl;
        std::cout << ans << std::endl;
        exit(0);
    }
    ll scy=0;
    rep(i,cy){
        scy+=x;
        x=(x*x)%m;
    }
    ll kai=(n-ni)/cy;
    ll ama=(n-ni)%cy;
    ans+=kai*scy;
    
    rep(i,ama){
        ans+=x;
        x=(x*x)%m;
    }
    std::cout << ans << std::endl;
    
    
    
}