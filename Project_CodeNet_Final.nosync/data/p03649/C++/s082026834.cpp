#include <iostream>
using namespace std;

int main() {
  long long N;
  long long a[50];

  cin >> N;
  for (long long i = 0; i < N; i++) {
    cin >> a[i];
  }

  long long ans = 0;
  while (1) {
    long long sum = 0;
    long long n[50];
    for (long long i = 0; i < N; i++) {
      n[i] = a[i] / N;
      sum += n[i];
      a[i] = a[i] % N;
    }
    for (long long i = 0; i < N; i++) {
      a[i] += sum - n[i];
    }
    ans += sum;
    if (sum == 0ll) {
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
