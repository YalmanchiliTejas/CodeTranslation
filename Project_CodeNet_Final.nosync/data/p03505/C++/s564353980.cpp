#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int64 K, A, B;
  cin >> K >> A >> B;

  int64 D = A - B;

  if(D <= 0) {
    if(A >= K) {
      cout << 1 << endl;
    } else {
      cout << -1 << endl;
    }
  } else {
    cout << 1 + 2 * ((K - A + D - 1) / D) << endl;
  }
}