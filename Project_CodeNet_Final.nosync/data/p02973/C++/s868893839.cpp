#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int main() {
  long N;
  cin >> N;

  deque<long> LDS;
  for (size_t n = 0; n < N; ++n) {
    long A;
    cin >> A;
    auto it = lower_bound(LDS.begin(), LDS.end(), A);
    if (it == LDS.begin()) LDS.push_front(A);
    else *(--it) = A;
  }
  cout << LDS.size() << endl;
  
  return 0;
}
