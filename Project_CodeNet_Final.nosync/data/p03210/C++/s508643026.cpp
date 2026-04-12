#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <boost/math/common_factor_rt.hpp>
using namespace std;
#define rep(i, n) for(int i = 0;i < n;i++)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ll long long

int main(){
  int N;
  cin >> N;

  if(N==3 || N==5 || N==7) cout << "YES" << endl;
  else cout << "NO" << endl;
}