#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (ll K = max(0ll, sum - (N - 1) * N); K < sum + N; K++) {
    ll ks = 0;
    for (int i = 0; i < N; i++) {
      ks += (a[i] + K + 1) / (N + 1); 
    }
    if (ks == K) {
      cout << K << endl;
      break;
    }
  }
  return 0;
}
