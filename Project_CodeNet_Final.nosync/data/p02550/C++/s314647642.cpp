#include <cstdint>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class runtime_modint {
  using u64 = std::uint_fast64_t;

  static u64 &mod() {
    static u64 mod_ = 0;
    return mod_;
  }

public:
  u64 a;

  runtime_modint(const u64 x = 0) : a(x % get_mod()) {}
  u64 &value() noexcept { return a; }
  const u64 &value() const noexcept { return a; }
  runtime_modint operator+(const runtime_modint rhs) const {
    return runtime_modint(*this) += rhs;
  }
  runtime_modint operator-(const runtime_modint rhs) const {
    return runtime_modint(*this) -= rhs;
  }
  runtime_modint operator*(const runtime_modint rhs) const {
    return runtime_modint(*this) *= rhs;
  }
  runtime_modint operator/(const runtime_modint rhs) const {
    return runtime_modint(*this) /= rhs;
  }
  runtime_modint &operator+=(const runtime_modint rhs) {
    a += rhs.a;
    if (a >= get_mod()) {
      a -= get_mod();
    }
    return *this;
  }
  runtime_modint &operator-=(const runtime_modint rhs) {
    if (a < rhs.a) {
      a += get_mod();
    }
    a -= rhs.a;
    return *this;
  }
  runtime_modint &operator*=(const runtime_modint rhs) {
    a = a * rhs.a % get_mod();
    return *this;
  }
  runtime_modint &operator/=(runtime_modint rhs) {
    u64 exp = get_mod() - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }

  static void set_mod(const u64 x) { mod() = x; }
  static u64 get_mod() { return mod(); }
};


int main(){
    uint_fast64_t n,x;
    uint_fast64_t m;
    cin >> n >> x >> m;
    runtime_modint::set_mod(m);
    runtime_modint xi;
    xi=x;
    uint_fast64_t sum=0;
    //vector<uint_fast64_t> sums(n);
    unordered_set<uint_fast64_t> xis;
    uint_fast64_t ls,le,ss,se,la;
    uint_fast64_t i=0;
    for(i=0;i<n;i++){
        uint_fast64_t a=xi.a;
        sum += a;
        //sums[n]=sum;
        if(xis.find(a)!= xis.end()){
          le=i;
          se=sum;
          la=a;
          goto loop;
        }
        xis.insert(a);
        xi = xi*xi;
    }
    cout << sum;
    return 0;
loop:
    xi=x;
    sum=0;
    for(i=0;i<n;i++){
      uint_fast64_t a=xi.a;
      //sums[n]=sum;
      sum += a;
      if(a == la){
        ls=i;
        ss=sum;
        goto loop2;
      }
      xi = xi*xi;
    }
loop2:
    sum+=(se-ss)*((n-i)/(le-ls) -1);
    i+=((n-i)/(le-ls) -1)*(le-ls);
    for(;i<n;i++){
        uint_fast64_t a=xi.a;
        sum += a;
        xi = xi*xi;
    }
    cout << sum-la;
    return 0;

}
