#include <stdio.h>		// standard input output
#include <iostream>		// input output stream, cin cout( console in console out)
#include <cmath>		// circle math ( sin, con, sinh
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>		// input output manipulation

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep3(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define ll long long

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }





int main() {
  ll N; // 変数の宣言
  cin >> N; // 標準入力
  vector<ll> A(N);
  ll sum =0;
  ll mod =1000000007;
  rep(i,N){
    cin >> A.at(i);
    sum += A[i];
    sum %=mod;
  }
  ll ans =0;

  rep(i,N){
    sum -=A[i];
    if(sum<0)
      sum = sum + mod;

    ans = ans + A[i]*sum;
    ans %= mod;
  }
 
  cout << setprecision(12) << ans << endl; // 標準出力
}

