#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int mod = 1000000007;
class mint {
    long long x;
public:
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }
    mint choose(int n, int a){
        mint x = 1 ,y = 1;
        for(int i = 0; i < a; ++i){
            x *= n-i;
            y *= i+1;
        }
        return x / y;
    }
    friend istream& operator>>(istream& is, mint& m){
        is >> m.x;
        return is;
    }
    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  ll sum=0;
  rep(i,n){
    cin>>a[i];
    sum+=a[i];
  }
  mint ans=0;
  rep(i,n){
    ans+=mint(sum-a[i])*a[i];
  }
  cout<<ans/2<<endl;
}