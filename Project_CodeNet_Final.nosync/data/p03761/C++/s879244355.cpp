#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

//long long
using ll = long long;

//出力系
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}


int main(){
  int N;
  cin >> N;
  vector<string>S(N);
  vector<int>B(26, MOD);
  REP(i, N) cin >> S.at(i);
  REP(i, N){
    vector<int>A(26, 0);
    REP(j, S.at(i).size()){
      A.at(S.at(i).at(j) - 'a')++;
    }
  
    REP(j, 26){
      if(A.at(j) < B.at(j)) B.at(j) = A.at(j);
    }
  
  
  }

REP(i, 26){
  REP(j, B.at(i)) {
    cout << (char)('a' + i);
  }
}
cout << endl;

}