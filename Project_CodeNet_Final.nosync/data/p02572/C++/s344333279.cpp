#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
struct mint {
  long long x;
  mint(long long x=0):x((x%mod+mod)%mod){}
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
  mint pow(long long t) const {
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
int N;
int main(){
    cin>>N;
    vector<long long>A(N+1),acc(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    acc[0]=0LL;
    for(int i=1;i<=N;i++)acc[i]=acc[i-1]+A[i];
    mint ans=0LL;
    for(int i=1;i<=N-1;i++){
        mint a=A[i];
        a*=acc[N]-acc[i];
        ans+=a;
    }
    cout<<ans<<endl;
    return 0;
}