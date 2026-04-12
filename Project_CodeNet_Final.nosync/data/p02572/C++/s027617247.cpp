#include <bits/stdc++.h>
using namespace std;

constexpr int64_t MOD= 1'000'000'007;
constexpr bool is_FACTORIAL_STORED= false; // 階乗を配列に格納をする前処理をする/しない
constexpr int Nfac= is_FACTORIAL_STORED ? 500'007
                                        : 0;
/* 剰余環 Z/nZ */
struct mint{ // Z/nZ に関する演算(n:素数の場合は除算も)をサポートする構造体
  int64_t rep; // 出力すべき代表元 rep \in {0,1,..,MOD- 1}
  mint(int64_t x=0): rep(((x%MOD)+ MOD)% MOD){}
  mint operator-() const { return mint(-rep);}
  mint& operator+=(const mint& x){
    rep+= x.rep; 
    if(rep>= MOD) rep-= MOD;
    return *this;
  }
  mint& operator-=(const mint& x){
    rep-= x.rep;
    if(rep< 0) rep+= MOD;
    return *this;
  }
  mint& operator*=(const mint& x){
    rep*= x.rep; rep%= MOD;
    return *this;
  }
  mint operator+(const mint x) const {
    mint ans(*this);
    ans+= x;
    return ans;
  }
  mint operator-(const mint x) const {
    mint ans(*this);
    ans-= x;
    return ans;
  }
  mint operator*(const mint x) const {
    mint ans(*this);
    ans*= x;
    return ans;
  }
  bool operator==(const mint x) const {
    return rep==x.rep;
  }
  bool operator!=(const mint x) const {
    return rep!=x.rep;
  }

  mint pow(int64_t d) const{
    assert(d >= 0); // ここで引っかかったら this.pow(d)= 0 or this.pow(-d).inv() のどちらかを選べ
    assert(!(*this==0 && d==0)); //   this.pow(d)= 0 or 1           　     のどちらかを選べ
    mint ans= 1;
    mint x= *this;
    while(d > 0){
      if(d&1){ ans*= x; }
      d >>= 1;
      x*= x;
    }

    return ans;
  }

  friend istream& operator >> (istream &is, mint& x) noexcept{
    int64_t a;
    is >> a;
    x= a;
    return is;
  }
  friend ostream& operator << (ostream &os, const mint& x) noexcept{
      return os << x.rep;
  }
  // MOD が素数(<=> Z/nZ が体)のとき
  mint inv() const{
    return pow(MOD-2);
  }
  mint& operator/=(const mint& x){
    *this *= x.inv();
    return *this;
  }
  mint operator/(const mint x) const {
    mint ans(*this);
    ans/= x;
    return ans;
  }
};

int main(){
  int N;
  cin >> N;

  vector<mint> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }

  vector<mint> cumsum_tail(N);
  for(int i=1; i <= N; i++){
    cumsum_tail.at(N-i)= (i==1) ? data.at(N-1)
                                : cumsum_tail.at(N-i+1)+ data.at(N-i);
  }

  mint ans= 0;
  for(int i=0; i+1 < N; i++){
    ans+= data.at(i)* cumsum_tail.at(i+1);
  }
  
  cout << ans << endl;
}