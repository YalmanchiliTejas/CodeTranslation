#include <bits/stdc++.h>
using namespace std;

int main() {
  long K, A, B;
  cin >> K >> A >> B;
  if (K <= A) cout << 1 << endl;
  else if (A <= B) cout << -1 << endl;
  else {
    K -= A;
    long tmp = (K - 1) / (A - B) + 1;
    cout << 1 + tmp * 2 << endl;
  }
}