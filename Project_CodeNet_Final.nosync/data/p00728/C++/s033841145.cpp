#include <iostream>
using namespace std;
int N,S;

int main() {
  while (cin >> N && N > 0) {
    int sum = 0, M = 0, m = 1e9;
    for (int i = 0; i < N; i++) {
      cin >> S;
      sum += S;
      if (M < S) M = S;
      if (m > S) m = S;
    }
    cout << (sum - M - m)/(N-2) << endl;
  }
}