#include <bits/stdc++.h> // ver2.4.1
#include <complex.h>
//#include <boost/math/tools/minima.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
#define fmin brent_find_minima
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define COUNT(a,k) upper_bound(ALL(a),k)-lower_bound(ALL(a),k)
#define BIGGER(a,k) a.end()-upper_bound(ALL(a),k)
#define SMALLER(a,k) lower_bound(ALL(a),k)-a.begin()
#define Vi vector<int>
#define VVi vector<Vi>
#define Vm vector<mint>
#define Vs vector<string>
#define Pii pair<int,int>
#define Pdd pair<double,double>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define VTiii vector<Tiii>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define itos to_string
#define stoi stoll
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define INF 3000000000000000000  //  3.0*10^18(MAXの1/3くらい)
#define MAX LLONG_MAX
#define PI 3.141592653589793238462
#define MOD 1000000007  //  10^9 + 7

using namespace std;
/* fmin(f,L,R,100) で関数の最小値を(x,min)で返す　*/
//using boost::math::tools::brent_find_minima;
/* cpp_int (任意の長さのint) */
//using boost::multiprecision::cpp_int;

/* デバッグ用 */
void Vout(auto a){if(a.size()==0) cout<<"."<<endl;
else{rep(i,0,a.size()-1)cout<<a[i]<<' ';if(a.size()>0)cout<<a.back()<<endl;}return;}
void Verr(auto a){if(a.size()==0) cerr<<"."<<endl;
else{rep(i,0,a.size()-1)cerr<<a[i]<<' ';if(a.size()>0)cerr<<a.back()<<endl;}return;}
void VVout(auto a){if(a.size()==0)cout<<"."<<endl;
else{rep(i,0,a.size())Vout(a[i]);}return;}
void VVerr(auto a){if(a.size()==0)cerr<<"."<<endl;
else{rep(i,0,a.size())Verr(a[i]);}return;}
void VPout(auto a){if(a.size()==0)cout<<"."<<endl;
else{rep(i,0,a.size())cout<<a[i].FI<<' '<<a[i].SE<<endl;}return;}
void VPerr(auto a){if(a.size()==0)cerr<<"."<<endl;
else{rep(i,0,a.size())cerr<<a[i].FI<<' '<<a[i].SE<<endl;}return;}

/* 便利関数 */
int gcd(int a,int b){return b?gcd(b,a%b):a;} // 最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;} // 最小公倍数lcm
int mypow(int x, int n, int m){ // 累乗x^n(mod m) O(log(n))
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}
int scomb(int n, int r){if((n-r)<r)r=n-r; // nCr(小さい場合)
int a=1;for(int i=n;i>n-r;--i){a=a*i;}for(int i=1;i<r+1;++i){a=a/i;}return a;}
int comb(int n, int r){if((n-r)<r)r=n-r; // nCr(%MOD)
int a=1;for(int i=n;i>n-r;--i){a=a*i%MOD;}for(int i=1;
i<r+1;++i){a=a*mypow(i,MOD-2,MOD)%MOD;}return a%MOD;}
Vi stpowV(){Vi a(100005);
a[0]=1;repeq(i,1,100004)a[i]=a[i-1]*i%MOD;return a;}
//Vi stpow = stpowV();  // 階乗配列(%MOD)
Vi Vsum(Vi &v){Vi S(v.size()+1);rep(i,1,S.size())S[i]+=v[i-1]+S[i-1];return S;}// 累積和
int digit(int k,int i){string s = itos(k);return s[s.size()-i]-'0';} // i桁目の数字
void press(auto &v){v.erase(unique(ALL(v)),v.end());} // 圧縮
Vi zip(Vi b){int Z=b.size(); // 座標圧縮
Pii p[Z+10];int a=b.size();Vi l(a);for(int i=0;i<a;i++)
p[i]=mp(b[i],i);sort(p,p+a);int w=0;for(int i=0;i<a;i++)
{if(i&&p[i].first!=p[i-1].first)w++;l[p[i].second]=w;}return l;}
Vi beki2V(){Vi a(61);int q = 1;rep(i,0,61){a[i]=q;q*=2;}return a;}
Vi beki2 = beki2V(); // 2^n配列
int modiv(int a,int b){return a*mypow(b,MOD-2,MOD)%MOD;} // a÷b(MOD環境)

struct mint { // 出力するときだけ.xをつける
  int x;
  mint(int x=0):x((x%MOD+MOD)%MOD){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
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
  mint pow(int t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  int n,m,k;
  cin >> n >> m >> k;
  
  Vm pin(200010),ko(200010);
  pin[1] = 1;
  ko[1] = 1;
  
  rep(i,2,200010){
    ko[i] = ko[i-1];
    ko[i] += i;
    pin[i] = pin[i-1];
    pin[i] += ko[i];
  }
  
  mint qw = pin[m-1];
  mint naname = 0;
  
  repeq(i,1,n-1){
    naname += (qw+ko[m-1]*i)*(n-i);
  }
  naname *= 2;
  
  //cerr << qw.x << endl;
  //cerr << naname.x << endl;
  
  mint nC2,mC2;
  nC2 = n;
  nC2 *= n-1;
  nC2 /= 2;
  mC2 = m;
  mC2 *= m-1;
  mC2 /= 2;
  /*
  mint nnmct = 2;
  nnmct *= nC2;
  nnmct *= mC2;
  
  naname /= nnmct;
  */
  //cerr << nnmct.x << endl;
  
  mint yoko,tate;
  yoko = pin[n-1];
  yoko *= m;
  tate = pin[m-1];
  tate *= n;
  
  //cerr << yoko.x + tate.x + naname.x << endl;
  
  mint ans = yoko+tate+naname;
  ans *= comb(n*m-2,k-2);
  cout << ans.x << endl;
  
  return 0;
}