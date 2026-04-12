#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<long long int> A(N);
  long long int A_sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    A.at(i) = A.at(i) % 1000000007;
    A_sum += A.at(i);
    A_sum = A_sum % 1000000007;
  }
  long long int ans = 0;
  for(int i = 0; i < N; i++) {
    ans = ans + A.at(i) * (A_sum - A.at(i) + 1000000007);
    ans = ans % 1000000007;
    if(A_sum > A.at(i)) {
      A_sum = A_sum - A.at(i);
    }
    else {
      A_sum = A_sum - A.at(i) + 1000000007;
    }
  }
  cout << ans << endl;
}