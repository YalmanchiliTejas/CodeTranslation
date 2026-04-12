#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define uniq(x) ((x).erase(unique(all(x)),(x).end()))
#define sz(x) ((int)(x).size())

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

#ifdef LOCAL//compile with -DLOCAL
#define debug(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl
#define debug_vec(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = ";\
  rep(i,sz(x)){cerr<<x[i]<<" ";}cerr<<endl
#define debug_mat(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<endl;\
  rep(i,sz(x)){rep(j,sz(x[i])){cerr<<x[i][j]<<" ";}cerr<<endl;}cerr<<endl
#else
#define debug(x) void(0)
#define debug_vec(x) void(0)
#define debug_mat(x) void(0)
#endif

template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
class modint{
public:
  long long x;
  constexpr modint(long long x=0):x((x%MOD+MOD)%MOD){}
  constexpr modint operator-() const{return modint(-x);}
  constexpr modint& operator+=(const modint& a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  constexpr modint& operator-=(const modint& a){
    if((x+=MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  constexpr modint& operator*=(const modint& a){
    (x*=a.x)%=MOD;
    return *this;
  }
  constexpr modint operator+(const modint& a) const{return modint(*this)+=a;}
  constexpr modint operator-(const modint& a) const{return modint(*this)-=a;}
  constexpr modint operator*(const modint& a) const{return modint(*this)*=a;}
  constexpr bool operator==(const modint& a) const{return this->x==a.x;}
  constexpr bool operator!=(const modint& a) const{return this->x!=a.x;}
  constexpr modint pow(long long expo) const{
    if(expo==0)  return 1;
    modint a=pow(expo>>1);
    a*=a;
    if(expo&1)  a*=(*this);
    return a;
  }
  //for prime MOD
  constexpr modint inv() const{return pow(MOD-2);}
  constexpr modint& operator/=(const modint& a){return (*this)*=a.inv();}
  constexpr modint operator/(const modint& a) const{return modint(*this)/=a;}
};
istream& operator>>(istream& is,const modint& a){return is >> a.x;}
ostream& operator<<(ostream& os,const modint& a){return os << a.x;}

//for binomial coefficients
const int MAX=510000;
vector<modint> fac(MAX,0);
vector<modint> finv(MAX,0);
vector<modint> inv(MAX,0);
void COMinit(){
  fac.at(0)=fac.at(1)=1;
  finv.at(0)=finv.at(1)=1;
  inv.at(1)=1;
  for(int i=2;i<MAX;i++){
    fac.at(i)=fac.at(i-1)*i;
    inv.at(i)=-inv.at(MOD%i)*(MOD/i);
    finv.at(i)=finv.at(i-1)*inv.at(i);
  }
}
modint COM(int n,int k){
  if(n<k) return 0;
  if(n<0 || k<0)  return 0;
  return fac.at(n)*finv.at(k)*finv.at(n-k);
}


int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N)  cin >> A.at(i);

  vector<modint> sum(N+1,0);
  for(int i=N-1;i>=0;i--) sum.at(i)=sum.at(i+1)+A.at(i);

  modint ans=0;
  rep(i,N){
    ans+=modint(A.at(i))*sum.at(i+1);
  }
  cout << ans << endl;

  return 0;
}