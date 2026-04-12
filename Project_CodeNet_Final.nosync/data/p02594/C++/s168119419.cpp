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
  int N; // 変数の宣言
  cin >> N; // 標準入力

  if(N>=30){
  cout << setprecision(12) << "Yes" << endl; // 標準出力
  }
  else{
     cout << setprecision(12) << "No" << endl;
  }
}
