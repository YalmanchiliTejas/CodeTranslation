#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
  int mod = 1000000007;
  int N;
  cin >> N;
  vector<int> A(N);
  long long sum = 0;
  rep(i, N) {
    cin >> A.at(i);
    sum += A.at(i);
    sum %=  mod;
  }
  long long ans = 0;
  rep(i, N) {
    sum -= A.at(i);
    if (sum < 0) sum += mod;
    ans += A.at(i) * sum;
    ans %= mod;
  }
  cout << ans;
}
