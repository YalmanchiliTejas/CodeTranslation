#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  int N;
  cin >> N;
  int X[N];
  int X_sorted[N];
  for(int i = 0; i < N; i++) {
    cin >> X[i];
    X_sorted[i] = X[i];
  }
  sort(X_sorted, X_sorted + N);
  int max_med = X_sorted[N / 2];
  int min_med = X_sorted[N / 2 - 1];
  for(int i = 0; i < N; i++) {
    if(X[i] <= min_med) {
      cout << max_med << endl;
    } else {
      cout << min_med << endl;
    }
  }
  return 0;
}
