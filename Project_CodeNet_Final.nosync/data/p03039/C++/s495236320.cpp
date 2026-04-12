#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MOD=1e9+7;

struct modint {
    int val;
    modint inv() const{
        int tmp,a=val,b=MOD,x=1,y=0;
        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
        return modint(x);
    }
public:
    modint():val(0){}
    modint(ll x){if((val=x%MOD)<0)val+=MOD;}
    modint pow(ll t){modint res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return res;}
    modint& operator+=(const modint& x){if((val+=x.val)>=MOD)val-=MOD;return *this;}
    modint& operator-=(const modint& x){if((val+=MOD-x.val)>=MOD)val-=MOD; return *this;}
    modint& operator*=(const modint& x){val=(ll)val*x.val%MOD; return *this;}
    modint& operator/=(const modint& x){return *this*=x.inv();}
    bool operator==(const modint& x) const{return val==x.val;}
    bool operator!=(const modint& x) const{return val!=x.val;}
    bool operator<(const modint& x) const{return val<x.val;}
    bool operator<=(const modint& x) const{return val<=x.val;}
    bool operator>(const modint& x) const{return val>x.val;}
    bool operator>=(const modint& x) const{return val>=x.val;}
    modint operator+(const modint& x) const{return modint(*this)+=x;}
    modint operator-(const modint& x) const{return modint(*this)-=x;}
    modint operator*(const modint& x) const{return modint(*this)*=x;}
    modint operator/(const modint& x) const{return modint(*this)/=x;}
};

struct factorial {
    vector<modint> Fact, Finv;
public:
    factorial(int _n): Fact(_n+1), Finv(_n+1) {
        Fact[0]=modint(1); for (int i = 0; i < _n; ++i) Fact[i+1]=Fact[i]*(i+1);
        Finv[_n]=modint(1)/Fact[_n]; for (int i = _n; i > 0; --i) Finv[i-1]=Finv[i]*i;
    }
    modint fact(int n,bool inv=0) { if (inv) return Finv[n]; else return Fact[n]; }
    modint nPr(int n,int r){ if (n<0||n<r||r<0) return modint(0); else return Fact[n]*Finv[n-r]; }
    modint nCr(int n,int r){ if (n<0||n<r||r<0) return modint(0); else return Fact[n]*Finv[r]*Finv[n-r]; }
};

// int main() {
//   // 6C3 % (1e9+7) = 20
//   cout << "6C3: " << fact.nCr(6,3).val << endl;
//   // 666C390 % (1e9+7) = 9951876
//   cout << "666C390: " << fact.nCr(666,390).val << endl;
// }


int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  factorial fact(1000010);
  modint ans = 0;
  for (int i = 1; i < m; ++i) {
    modint tmp(n);
    tmp *= n;
    tmp *= i;
    tmp *= (m-i);
    ans += tmp;
  }
  for (int i = 1; i < n; ++i) {
    modint tmp(m);
    tmp *= m;
    tmp *= i;
    tmp *= (n-i);
    ans += tmp;
  }
  ans *= fact.nCr(n*m-2, k-2);
  cout << ans.val << endl;
}

