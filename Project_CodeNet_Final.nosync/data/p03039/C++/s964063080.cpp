#include <bits/stdc++.h>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;
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
  ll N,M,K;
  cin >> N >> M >> K;

  COMinit();
  modint ans=0;
  for(ll i=0;i<N;i++){
    for(ll j=0;j<M;j++){
      ans+=(i+1)*(j+1)*((i+1)-1+(j+1)-1)/2;
      ans+=(i+1)*(M-j)*((i+1)-1+(M-j)-1)/2;
      ans+=(N-i)*(j+1)*((N-i)-1+(j+1)-1)/2;
      ans+=(N-i)*(M-j)*((N-i)-1+(M-j)-1)/2;
      ans-=(i+1)*((i+1)-1)/2;
      ans-=(j+1)*((j+1)-1)/2;
      ans-=(N-i)*((N-i)-1)/2;
      ans-=(M-j)*((M-j)-1)/2;
    }
  }
  ans/=2;
  ans*=COM(N*M-2,K-2);
  cout << ans << endl;

  return 0;
}