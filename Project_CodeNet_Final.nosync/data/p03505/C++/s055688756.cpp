#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long K, A, B; cin >> K >> A >> B;
  long long m, s;
  m = A-B, s = max(K-A, 0LL);
  if(s > 0) {
    if(m <= 0) {
      cout << -1 << endl;
    } else {
      cout << 1 + 2*((s+m-1)/m) << endl;
    }
  } else {
    cout << 1 << endl;
  }
  return 0;
}
