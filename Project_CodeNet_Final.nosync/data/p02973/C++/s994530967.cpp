#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<int> A, L;

// 広義最長減少部分列の長さ
int solve(){
  L[0] = A[0];
  int length = 1;
  for (int i = 1; i < N; i++) {
    if (L[length - 1] <= A[i]) {
      L[length] = A[i];
      length++;
    } else {
      auto iter = upper_bound(L.begin(), L.begin() + length, A[i]);
      L[iter - L.begin()] = A[i];
    }
  }
  return length;
}
int main() {
  cin >> N;
  A.resize(N);
  L.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] = - A[i];
  }
  cout << solve() << "\n";
  return 0;
}