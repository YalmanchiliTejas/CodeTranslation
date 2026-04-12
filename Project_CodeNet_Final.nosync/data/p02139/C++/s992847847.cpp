#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

// ねね
int main() {
  int N, Q;
  cin >> N >> Q;
  int now = 0;
  for(int i = 0; i < Q; i++) {
    int T, K;
    cin >> T >> K;
    if(T == 1) {
      (now += K) %= N;
    } else {
      cout << (now + K - 1) % N + 1 << endl;
    }
  }
}


