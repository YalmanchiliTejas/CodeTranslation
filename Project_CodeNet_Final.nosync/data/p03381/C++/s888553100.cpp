#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N + 1);
  for (int i = 1; i <= N; i++) cin >> X[i];
  vector<int> Y = X;
  sort(Y.begin(), Y.end());
  for (int i = 1; i <= N; i++) {
    if (X[i] <= Y[N / 2]) cout << Y[N / 2 + 1] << endl;
    else cout << Y[N / 2] << endl;
  }
  return 0;
}