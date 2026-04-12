#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)

#define ALL(v) v.begin(), v.end()


int64_t N;
vector<int64_t> A;


int64_t MOD = MOD = 1000000007;

int main() {
  std::cout << std::fixed << std::setprecision(20);

  cin >> N;
  
  A = vector<int64_t>(N,0);

  REP(i,N){
    cin >> A[i];
  }

  int64_t x = 0;
  REP(i,N){
    x += A[i];
    x %= MOD;
  }

  int64_t ans = 0;
  REP(i, N-1){
    x = x - A[i];
    x %= MOD;
    if(x < 0){
      x += MOD;
    }
    ans += A[i] * x;
    ans %= MOD;
    
  }
  
  
  cout << ans << endl;

}