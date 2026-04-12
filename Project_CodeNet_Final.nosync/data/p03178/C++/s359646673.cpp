#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
void dprintf(const char *format, ...) {
  va_list arg;
  va_start (arg, format);
  vfprintf(stderr, format, arg);
  va_end(arg);
}
#define debug(arg) cerr << #arg << " = " << arg << endl;
#else
#define dprintf(...)
#define debug(x)
#endif
using ll = long long;



const int MOD = 1e9 + 7;
const int MAX_N = 10000;
const int MAX_D = 100;

int Count[2][MAX_N + 1][1 + MAX_D];

void addSelf(int &a, int b) {
  a += b;
  if (a >= MOD)
    a -= MOD;
}

int main() {
  string K;
  cin >> K;
  reverse(K.begin(), K.end());
  for (char &c : K) {
    c -= '0';
  }
  int D;
  cin >> D;
  Count[true][0][0] = 1;
  for (int i = 0; i < (int)K.size(); i++) {
    for (int d = 0; d <= D; d++) {
      for (int digit = 0; digit <= 9; digit++) {
        for (bool leq : {true, false}) {
          bool LEQ = (digit < K[i] || (digit == K[i] && leq));
          addSelf(Count[LEQ][i + 1][(d + digit) % D], Count[leq][i][d]);
        }
      }
    }
    //printf("%d %d\n", Count[true][i][0], Count[false][i][0]);
  }
  int answer = (Count[true][(int)K.size()][0] - 1 + MOD) % MOD;
  printf("%d\n", answer);
  return 0;
}
