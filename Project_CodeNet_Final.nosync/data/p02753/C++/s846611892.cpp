#include <bits/stdc++.h>
using namespace std;

constexpr int64_t INF = 1'010'000'000'000'000'017LL;
constexpr int64_t MOD = 1'000'000'007LL;
constexpr double EPS = 1e-12;
constexpr double PI = 3.14159265358979323846;

#define FOR(i, start, end) for(int64_t i=start; i<end; i++)
#define REP(i, n) FOR(i, 0, n)

// 最大公約数gcd
uint64_t gcd(uint64_t m, uint64_t n) {
  uint64_t temp;
  while (m % n != 0){
    temp = n;
    n = m % n;
    m = temp;
  }
  return n;
}

// 最小公倍数lcm=m*n/gcd
uint64_t lcm(uint64_t m, uint64_t n) {
  return (m*n)/gcd(m,n);
}

// nCm
void comb(vector<vector <uint64_t> > &v){
  for(uint64_t i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(uint64_t k = 1;k <v.size();k++){
    for(uint64_t j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}

signed main() {
  char s, sprev;
  sprev = 0;
  for(int i=0; i<3; i++){
    cin >> s;
    if(sprev!=0 && sprev != s){
      cout << "Yes" << endl;
      return 0;
    }
    sprev = s;
  }
  cout << "No" << endl;
  return 0;
}