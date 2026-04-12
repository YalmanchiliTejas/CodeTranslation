#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};


const int MOD = 1000000007;
using mint = Fp<MOD>;


int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}
int gyaku(int n){
    return modpow(n,MOD-2);
}

//素因数分解でそれぞれの素数がいくつ出てきたかを保存するmap
auto pfactor(int n){
  map<int,int> res;
  int t=sqrt(n);
  for(int i=2;i<=t;i++){
    for(;n%i==0;n/=i)res[i]++;
  }
  if(n>1)res[n]++;
  return res;
}
vector<int>kai(0);
void kaizyou(vector<int>&kai){
    rep(i,kai.size()){
        kai[i+1]=kai[i]*(i+1)%MOD;
      }
  }
int comb(int a,int b){
  return (kai[a]*gyaku(kai[a-b]))%MOD*gyaku(kai[b])%MOD;
}
////////////////////////////////////////////////////////////////////////
signed main() {
  int n;
  cin>>n;
  vector<int>v(n);
  rep(i,n)cin>>v[i];
  sort(v.begin(),v.end());
  int ans=0,count=1,l=1,r=0,c1=v[0],c2=v[0];
  while(count<n){
    if(count+2>n){
      ans+=max(v[l]-c1,v[l]-c2);
      break;
    }
    if(l>r){
      ans+=v[n-r-1]+v[n-r-2]-c1-c2;
      c1=v[n-r-1];
      c2=v[n-r-2];
      r+=2;
      count+=2;
    }
    else{
      ans+=-v[l]-v[l+1]+c1+c2;
      c1=v[l];
      c2=v[l+1];
      l+=2;
      count+=2;
    }
  }
  
  int ans2=0;
  count=1,l=0,r=1,c1=v[n-1],c2=v[n-1];
  while(count<n){
    if(count+2>n){
      ans2+=max(v[l]-c1,v[l]-c2);
      break;
    }
    if(l>r){
      ans2+=v[n-r-1]+v[n-r-2]-c1-c2;
      c1=v[n-r-1];
      c2=v[n-r-2];
      r+=2;
      count+=2;
    }
    else{
      ans2+=-v[l]-v[l+1]+c1+c2;
      c1=v[l];
      c2=v[l+1];
      l+=2;
      count+=2;
    }
  }
  ans=max(ans,ans2);
  cout<<ans<<endl;
  }
