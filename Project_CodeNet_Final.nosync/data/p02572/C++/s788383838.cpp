#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i = 0; i < (int64_t)(n); i++)
#define P 1000000007

int main() {
  //input
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  rep(i,N) {
    cin >> A.at(i);
  }
  //calc
  int64_t ans = 0;
  int64_t S = 0;
  for(int i = N-2; i >= 0; i--) {
    S += A.at(i+1);
    S %= P;
    ans += A.at(i) * S;
    ans %= P;
  }
  //output
  cout << ans << endl;
}