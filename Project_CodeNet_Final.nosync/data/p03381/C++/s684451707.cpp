#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int> B = A;
  sort(B.begin(), B.end());
  int a = B[(N - 1) / 2], b = B[N / 2];
  for (int i = 0; i < N; i++) {
    if (A[i] <= a) {
      cout << b << endl;
    } else if (A[i] >= b) {
      cout << a << endl;
    }
  }

  return 0;
}