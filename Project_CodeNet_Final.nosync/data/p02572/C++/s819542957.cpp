#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<long long> B(N + 1), C(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
    B.at(i + 1) = B.at(i) + A.at(i);
  }
  long long ans = 0;
  
  for(int i = 0; i < N - 1; i++){
    C.at(i) = (B.at(N) - B.at(i + 1)) % 1000000007;
    ans += A.at(i) * C.at(i);
    ans %= 1000000007;
  }
  
  cout << ans << endl;
}