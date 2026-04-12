#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t MOD = 1000000007;
  int N;
  cin >> N;
  int64_t A = 0;
  int64_t B = 0;
  for(int i = 0; i < N; i++) {
    int64_t x;
    cin >> x;
    A += x;
    B += x * x;
    B %= MOD;
  }
  A %= MOD;
  int64_t C = (A * A - B + MOD) % MOD;
  if(C % 2 == 0) {
    cout << C / 2 << endl;
  }
  else {
    cout << (C + MOD) / 2 << endl;
  }
}