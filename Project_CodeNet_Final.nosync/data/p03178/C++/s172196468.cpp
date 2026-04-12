#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;

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

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  string S;
  int D;
  cin >> S >> D;
  int N=sz(S);

  vector<vector<vector<modint>>> dp(N+1,vector<vector<modint>>(2,vector<modint>(D,0)));
  dp.at(0).at(1).at(0)=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<D;k++){
        if(j==0){
          for(int l=0;l<10;l++) dp.at(i+1).at(0).at((k+l)%D)+=dp.at(i).at(0).at(k);
        }
        else if(j==1){
          int tmp=S.at(i)-'0';
          for(int l=0;l<tmp;l++)  dp.at(i+1).at(0).at((k+l)%D)+=dp.at(i).at(1).at(k);
          dp.at(i+1).at(1).at((k+tmp)%D)+=dp.at(i).at(1).at(k);
        }
      }
    }
  }
  cout << dp.at(N).at(0).at(0) -1 +dp.at(N).at(1).at(0) << endl;

  return 0;
}