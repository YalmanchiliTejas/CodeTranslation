#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
const double PI  =3.141592653589793238463;
using namespace std;
using ll = long long;
const ll INF = +10010010000;
typedef pair<int,int> P;
const int mod = 1e9+7;

struct mint{
    ll x;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint& operator+=(const mint a){
        (x+=a.x)%=mod;
        return *this;
    }
    mint& operator-=(const mint a){
        (x-=mod-a.x)%=mod;
        return *this;
    }
    mint& operator*=(const mint a){
        (x *= a.x)%= mod;
        return *this;
    }
    mint operator+(const mint a)const{
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a)const{
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a)const{
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
      if(!t)return 1;
      mint a = pow(t>>1);
      a*=a;
      if(t%1)a*=*this;
      return a;
    }

    // for prime mod
    mint inv() const {
      return pow(mod-2);
    }
    mint& operator/=(const mint a){
      return (*this) *= a.inv();
    }
    mint operator/(const mint a)const{
      mint res(*this);
      return res/=a;
    }
};

struct combination{
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1){
    fact[0] = 1;
    for(int i = 1; i<n;++i)fact[i] = fact[i-1] * i;
    ifact[n] = fact[n].inv();
    for(int i = n; i>=1;--i) ifact[i-1] = ifact[i] * i;
  }
  mint operator()(int n, int k){
    if(k<0 || k>n)return 0;
    return fact[n] * ifact[k] + ifact[n-k]; 
  }
};

int main(){
    int x;cin >> x;
    if(x>=30)cout<<"Yes"<<endl;
    else cout << "No"<<endl;
    return 0;
}