#include <bits/stdc++.h>
using namespace std;

const int64_t MOD= 998244353;
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

  mint pow(int64_t d) const{ // d \geq 0
    if(d==0) return 1;
    else{
      mint ans= pow(d>>1);
      ans*= ans;
      if(d&1){ ans*= *this; }

      return ans;
    }
  }

  friend istream& operator >> (istream &is, mint& x) noexcept{
    return is >> x.rep;
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
// g(R):= \sum_{L in [1,R]} f(L,R) とおくと,
// ans  = \sum_{R in [1,N]} g(R).
// よってg(R) を順次求めればいい。まず、
// f(L,R)=  [x^S] \prod_{i in [L,R]} (1+ x^{A_i})
//       =: [x^S] F_{L,R} とおく. このとき、
// g(R)=  \sum_{L in [1,R]} [x^S] F_{L,R}
//     =  [x^S] \sum_{L in [1,R]} F_{L,R}
//     =: [x^S] G_R
//     =  [x^S] G_{R-1}(1+ x^{A_R})+ (1+ x^{A_R})
//     =  [x^S] (1+ G_{R-1}) (1+ x^{A_R}).
// まとめると、G_R= (1+ G_{R-1}) (1+ x^{A_R}), G_0= 0 の各係数をDPで順次求めていけばいい。
  int N,S;
  cin >> N >> S;

  vector<int> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }

  vector<mint> dp(S+1);
  vector<mint> buf(S+1);
  mint ans= 0;
  for(int i=0; i<N; i++){
    dp.at(0)+= 1;
    for(int s=0; s<=S; s++){
      buf.at(s)= (s >= data.at(i)) ? dp.at(s)+ dp.at(s- data.at(i))
                                   : dp.at(s);
    }

    for(int s=0; s<=S; s++){
      dp.at(s)= buf.at(s);
    }
    ans+= buf.at(S);
  }

  cout << ans << endl; 
}