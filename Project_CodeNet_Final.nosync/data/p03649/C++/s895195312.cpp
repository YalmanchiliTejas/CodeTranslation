#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N;
  cin >> N;

  vector<long long> a(N);
  for (long long i = 0; i < N; i++) {
    cin >> a[i];
  }

  long long sum = 0;
  bool f = true;
  while (f) {
    f = false;

    for (long long i = 0; i < N; i++) {
      long long k = a[i] / N;
      if (k == 0) {
	continue;
      }

      a[i] -= k * N;
      sum += k;
      f = true;

      for (long long j = 0; j < N; j++) {
	if (j == i) {
	  continue;
	}

	a[j] += k;
      }
    }
  }

  cout << sum << endl;

  return 0;
}
