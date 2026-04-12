#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <string>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC target("avx512f,avx512dq,avx512cd,avx512bw,avx512vl")
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x;
  cin >> x;
  if(x>=30){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }

  return 0;
}