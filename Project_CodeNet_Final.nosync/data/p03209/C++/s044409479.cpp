#include <bits/stdc++.h>

using namespace std;

#define INF 0x7FFFFFFF

unsigned long long all[51];
unsigned long long patty[51];

unsigned long long search(int N, unsigned long long X) {
  if (N == 0) {
    return X == 1 ? 1 : 0;
  }
  
  if (1 < X && X < 2 + all[N - 1]) {
    return search(N - 1, X - 1);
  }
  
  if (X == 2 + all[N - 1]) {
    return patty[N - 1] + 1;
  }
  
  if (2 + all[N - 1] < X && X < all[N]) {
    return patty[N - 1] + 1 + search(N - 1, X - 2 - all[N - 1]);
  }
  
  if (X == all[N]) {
    return patty[N];
  }
}

int main() {
  int N;
  unsigned long long X;
  
  cin >> N >> X;
  
  all[0]	= 1;
  patty[0]	= 1;
  
  for (int i = 1; i <= N; i++) {
    all[i]		= 2 * all[i - 1] + 3;
    patty[i]	= 2 * patty[i - 1] + 1;
  }
  
  cout << search(N, X) << endl;
  
  return 0;
}