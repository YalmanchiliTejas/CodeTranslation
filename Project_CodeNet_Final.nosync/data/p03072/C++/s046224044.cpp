#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve(ll N, vector<ll> H) {
  int ma{};
  int ans{};
  for(auto i=0; i!=N; ++i) {
    if (ma <= H[i]) {
      ma = H[i];
      ++ans;
    }
  }
  cout << ans << endl;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  solve(N, move(H));
  return 0;
}
