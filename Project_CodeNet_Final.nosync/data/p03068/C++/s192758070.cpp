#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void showIntArray(string a, int n) {
  for (int i=0; i<n; i++) {
    cout << a[i];
  } cout << endl;
}

int main() {
  int N, K;
  string S;
  cin >> N;
  char target;
  for (int i=0; i<N; i++) {
    cin >> S[i];
  }
  cin >> K;
  target = S[K-1];
  for (int i=0; i<N; i++) {
    if (i == K-1) {
      ;
    }
    else if (S[i] != target) {
      S[i] = '*';
    }
  }
  showIntArray(S, N);
  return 0;
}