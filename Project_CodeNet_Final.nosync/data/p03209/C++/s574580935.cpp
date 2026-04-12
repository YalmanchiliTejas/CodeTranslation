#include <iostream>
#include <vector>

using namespace std;

long long int countPatty(long long int N, long long int X, vector<long long int> &layer, vector<long long int> &patty) {
  long long int res = 0;
  if (N == 0) {
    if (X == 0) {
      return 0;
    } else {
      return 1;
    }
  }
  
  if (X >= 1) {
    X--;
  }
  
  if (X >= layer[N - 1]) {
    res += patty[N - 1];
    X -= layer[N - 1];
    if (X >= 1) {
      res++;
      X--;
    }
  }
  
  res += countPatty(N - 1, X, layer, patty);
  
  return res;
}

int main() {
  long long int N, X;
  cin >> N >> X;
  
  vector<long long int> layer(N + 1), patty(N + 1);
  layer[0] = 1;
  patty[0] = 1;
  
  // cout << N << endl;
  for (int i = 1; i <= N; i++) {
    layer[i] = 2 * layer[i - 1] + 3;
    patty[i] = 2 * patty[i - 1] + 1;
    //cout << layer[i] << " " << patty[i] << endl;
  }
  
  cout << countPatty(N, X, layer, patty) << endl;
  
  return 0;
}