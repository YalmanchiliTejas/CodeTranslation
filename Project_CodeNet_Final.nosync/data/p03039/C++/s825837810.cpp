#include<iostream>
using namespace std;
 
class ModInt{
  static const int default_mod = 1e9 + 7;
public:
  ModInt(long long val, int mod)
    : val(val % mod), mod(mod)
  {
  }
  ModInt(long long val)
    : ModInt(val, default_mod)
  {
  }
  ModInt operator* (const ModInt& another){
    return ModInt(val * another.val);
  }
    ModInt operator+ (const ModInt& another){
        return ModInt(val + another.val);
    }
  ModInt& operator*=(const long long rhs){
    this->val *= rhs;
    this->val %= mod;
    return *this;
  }
  
  ModInt pow(long long exponent){
    exponent %= mod;
    if(exponent == 0){
      return ModInt(1, mod);
    }else{
      if(exponent % 2){
        return ((*this) * (*this)).pow(exponent / 2) * (*this);
      }else{
        return ((*this) * (*this)).pow(exponent / 2);
      }
    }
  }
  ModInt inv(){
    return this->pow(mod - 2);
  }
  static ModInt fact(long long n, int mod){
    n %= mod;
    auto ret = ModInt(1, mod);
    while(n > 1){
      ret *= n;
      n--;
    }
    return ret;
  }
  static ModInt fact(long long n){
    return ModInt::fact(n, default_mod);
  }
  static ModInt comb(long long n, long long r, int mod){
    if(r > n){
      return ModInt(0, mod);
    }
    return ModInt::fact(n) * ModInt::fact(r).inv() * ModInt::fact(n - r).inv();
  }
  static ModInt comb(long long n, long long r){
    return ModInt::comb(n, r, default_mod);
  }
 
  friend ostream& operator<< (ostream& os, const ModInt& modint){
    os << modint.val;
    return os;
  }
  friend istream& operator>>(istream& is, ModInt& modint){
    long long val;
    cin >> val;
    modint.val = val % modint.mod;
  }
private:
  long long val;
  int mod;
};

long long N, M, K;

int main(){
    cin >> N >> M >> K;
    auto ans_x = ModInt(6).inv() * ModInt(M) * ModInt(M) * ModInt::comb(N * M - 2, K - 2) * ModInt(N) * ModInt(N - 1) * ModInt(N + 1);
    auto ans_y = ModInt(6).inv() * ModInt(N) * ModInt(N) * ModInt::comb(N * M - 2, K - 2) * ModInt(M) * ModInt(M - 1) * ModInt(M + 1);

    cout << ans_x + ans_y << endl;
}
