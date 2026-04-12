#include<iostream>
#include<vector>
using namespace std;
 
class ModInt{
private:
  long long val;
  static const int default_mod = 1e9 + 7;
  static int mod;
  static vector<ModInt> facts;
public:
  ModInt(long long val)
  {
    if(mod == 0){
      mod = default_mod;
    }
    this->val = ((val % mod) + mod) % mod;
  }
  ModInt()
    : ModInt(0)
  {
  }
  static void setMod(int mod){
    if(ModInt::mod != 0){
      throw "The modulo is already set.";
    }
    ModInt::mod = mod;
  }

  const ModInt operator* (const ModInt& another) const{
    return ModInt(val * another.val);
  }
  ModInt operator+ (const ModInt& another){
    return ModInt(val + another.val);
  }
  ModInt operator- (const ModInt & another){
    return ModInt(val - another.val + mod);
  }
  ModInt operator/(const ModInt& rhs){
    return (*this) * rhs.inv();
  }
  ModInt& operator*=(const ModInt& rhs){
    (*this) = (*this) * rhs;
    return *this;
  }
  ModInt& operator+=(const ModInt& rhs){
    (*this) = (*this) + rhs;
    return *this;
  }
  ModInt& operator-=(const ModInt& rhs){
    (*this) = (*this) - rhs;
    return *this;
  }
  ModInt& operator/=(const ModInt& rhs){
    (*this) = (*this) / rhs;
    return *this;
  }
  ModInt pow(long long exponent) const{
    exponent %= mod - 1;
    if(exponent == 0){
      return ModInt(1);
    }else{
      if(exponent % 2){
        return ((*this) * (*this)).pow(exponent / 2) * (*this);
      }else{
        return ((*this) * (*this)).pow(exponent / 2);
      }
    }
  }
  ModInt inv() const{
    return this->pow(mod - 2);
  }
  static ModInt fact(long long n){
    if(n >= mod){
      return 0;
    }
    if(facts.size() < static_cast<size_t>(n + 1)){
      if(facts.size() == 0){
        facts.push_back(1);
      }
      for(int i = facts.size(); i <= n; i++){
        facts.push_back(facts[i - 1] * i);
      }
    }
    return facts[n];
  }
  static ModInt comb(long long n, long long r){
    if(r > n){
      return 0;
    }
    return ModInt::fact(n) * ModInt::fact(r).inv() * ModInt::fact(n - r).inv();
  }
 
  friend ostream& operator<< (ostream& os, const ModInt& modint){
    os << modint.val;
    return os;
  }
  friend istream& operator>>(istream& is, ModInt& modint){
    long long val;
    is >> val;
    modint.val = val % modint.mod;
    return is;
  }
  friend ModInt operator*(const long long lhs, const ModInt& rhs){
    return ModInt(lhs) * rhs;
  }
};
int ModInt::mod = 0;
vector<ModInt> ModInt::facts;

int main(){
  string K;
  cin >> K;
  int L = K.length();
  
  int D;
  cin >> D;

  // dp_full[l][d] := the number of numbers which is d mod D and whose top l digits are the same as K
  // dp_sm[l][d] := top l digits are smaller than K
  // ans = dp_full[L][0] + dp_sm[L][0];
  // dp_full[0][0] = 1, dp_sm[0][d] = 0
  // dp_full[l][d] = dp_full[l - 1][d - K[l - 1]]
  // dp_sm[l][d] = dp_sm[l - 1][d - 0] + ... + dp_sm[l - 1][d - 9] + dp_full[l - 1][d - 0] + ... + dp_full[l - 1][d - K[l - 1] - 1]
  vector<vector<ModInt>> dp_full(L + 1, vector<ModInt>(D)), dp_sm(L + 1, vector<ModInt>(D));
  dp_full[0][0] = 1;

  for(int l = 1; l <= L; l++){
    for(int d = 0; d < D; d++){
      int num = K[l - 1] - '0';
      dp_full[l][d] = dp_full[l - 1][((d - num) % D + D) % D];
      for(int dig = 0; dig < 10; dig++){
        dp_sm[l][d] += dp_sm[l - 1][((d - dig) % D + D) % D];
      }
      for(int dig = 0; dig < num; dig++){
        dp_sm[l][d] += dp_full[l - 1][((d - dig) % D + D) % D];
      }
    }
  }
  // -1 for 0
  cout << dp_full[L][0] + dp_sm[L][0] - 1 << endl;
}

