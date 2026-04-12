#include<iostream>
using namespace std;
typedef long long li;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
struct modint{
  li num;

  modint(li a=0){
    num=(a%MOD+MOD)%MOD;
  }
  modint operator+(modint a) {return{(num+a.num)%MOD};} 
  modint operator-(modint a) {return{((num-a.num)%MOD+MOD)%MOD};}
  modint operator*(modint a) {return{num*a.num%MOD};}
  modint inv(const modint& a);
  modint operator/(modint a) {return (*this)*inv(a);}
  modint& operator+=(modint a) {
    (num += a.num)%=MOD;
    return *this;
  }
  modint& operator*=(modint a) {
    (num*=a.num)%=MOD;
    return *this;
  }
};

std::ostream& operator<<(std::ostream& os, const modint& m){
  // ここでストリームに obj を書き込みます。
  li a=m.num;
  a%=MOD;
  a+=MOD;
  a%=MOD;
  cout << a;
  return os;
}

std::istream& operator>>(std::istream& os,modint& m){
  // ここでストリームに obj を書き込みます。
  li a; cin >>a;
  m=a;
  return os;
}

modint pow(modint a,int r){
  if(df)print(a,"^",r,"=");
  modint b=a,ans=1;
  while(r){
    if(r%2) ans*=b;
    b*=b;
    r/=2;
  }
  if(df)print(ans);
  return ans;
}

modint modint::inv(const modint& a){
  // MOD: prime
  return pow(a,MOD-2);
}


modint binom(li n,int k){
  if((k<0) or (k>n)) return 0;
  if(k>n-k) k=n-k;
  if(n<MOD){
    modint den=1,num=1;
    rep(i,k){
      den*=i+1;
      num*=n-i;
    }
    if(df)print("binom=",num,"/",den);
    return num/den;
  }
  while(1) print("too large");
}



int main(){
  int n,m;int k; cin >>n >>m >>k;
  if(df)print(m,n);
  modint ans=binom(m*n-2,k-2);
  if(df)print(m*n-2,k-2,ans);
  ans*=m*n;
  if(df)print("->",ans);
  ans*=m*n-1;
  if(df)print("->",ans);
  ans*=m+n;
  if(df)print("->",ans);
  ans=ans/6;
  print(ans);
}
