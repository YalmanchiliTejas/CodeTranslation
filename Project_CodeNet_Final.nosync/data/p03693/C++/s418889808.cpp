#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  if ((r * 100 + g * 10 + b) % 4 == 0){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
  return 0;
}