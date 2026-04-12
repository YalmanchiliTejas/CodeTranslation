// ライブラリ
#include<vector>
// 補助関数
template<typename T> T modpow(T x, T p, T M) {
  if(!p) return 1;
  if(p & 1) return (x * modpow(x, p - 1, M)) % M;
  return modpow((x * x) % M, p >> 1, M);
}
// 剰余類
template<typename T, T M = T(1e9 + 7)>
struct ModInt {
  T number;
  ModInt(T n = 0) : number(n % M) {while(number < 0) number += M;}
  // 代入演算
  ModInt& operator+=(const ModInt& m) {return *this = *this + m;}
  ModInt& operator-=(const ModInt& m) {return *this = *this - m;}
  ModInt& operator*=(const ModInt& m) {return *this = *this * m;}
  ModInt& operator/=(const ModInt& m) {return *this = *this / m;}
  ModInt& operator%=(const ModInt& m) {return *this = *this % m;}
  // 二項演算
  friend const ModInt operator+(const ModInt& lhs, const ModInt& rhs) {return lhs.number + rhs.number;}
  friend const ModInt operator-(const ModInt& lhs, const ModInt& rhs) {return lhs.number - rhs.number;}
  friend const ModInt operator*(const ModInt& lhs, const ModInt& rhs) {return lhs.number * rhs.number;}
  friend const ModInt operator/(const ModInt& lhs, const ModInt& rhs) {return lhs.number * modpow(rhs.number, M - 2, M);}
  friend const ModInt operator%(const ModInt& lhs, const ModInt& rhs) {return lhs.number % rhs.number;}
  // 関係演算
  friend bool operator==(const ModInt& lhs, const ModInt& rhs) {return lhs.number == rhs.number;}
  friend bool operator!=(const ModInt& lhs, const ModInt& rhs) {return lhs.number != rhs.number;}
  friend bool operator<=(const ModInt& lhs, const ModInt& rhs) {return lhs.number <= rhs.number;}
  friend bool operator>=(const ModInt& lhs, const ModInt& rhs) {return lhs.number >= rhs.number;}
  friend bool operator<(const ModInt& lhs, const ModInt& rhs) {return lhs.number < rhs.number;}
  friend bool operator>(const ModInt& lhs, const ModInt& rhs) {return lhs.number > rhs.number;}
  // 組み合わせ
  friend ModInt combination(const ModInt& n, const ModInt& r) {
    static std::vector<T> fact{1, 1}, inv{1, 1}, finv{1, 1};
    if(n < r) return 0;
    if(n < 0 || r < 0) return 0;
    for(T i = fact.size(); i <= n; ++i) {
      fact.emplace_back(fact.back() * i % M);
      inv.emplace_back(inv.at(M % i) * (M - M / i) % M);
      finv.emplace_back(finv.back() * inv.back() % M);
    }
    return (fact.at(n.number) * finv.at((n - r).number) % M) * finv.at(r.number) % M;
  }
};
// 入出力ストリーム
#include<iostream>
template<typename T, T M> inline std::istream& operator>>(std::istream& is, ModInt<T, M>& m) {return is >> m.number;}
template<typename T, T M> inline std::ostream& operator<<(std::ostream& os, const ModInt<T, M>& m) {return os << m.number;}

#include<bits/stdc++.h>
using namespace std;

int main() {
  using I = ModInt<long long, (long long)(1e9 + 7)>;

  I H, W, K;
  cin >> H >> W >> K;

  vector<vector<I>> s(H.number+1, vector<I>(W.number+1));
  for(auto h=1; h<=H; ++h) for(auto w=1; w<=W; ++w) s[h][w] += h + w - 1;
  for(auto h=1; h<=H; ++h) for(auto w=1; w<=W; ++w) s[h][w] += s[h-1][w] + s[h][w-1] - s[h-1][w-1];

  I res = 0;
  I pair = combination(H*W-2, K-2);
  for(auto h=1; h<=H; ++h) for(auto w=1; w<=W; ++w) {
    res += pair * s[(H-h+1).number][(W-w).number];
    res += pair * s[(H-h).number][(W-w+1).number];
  }
  cout << res << endl;
}
