#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> A[200000];
bool S[200000];

int main() {
  cin >> N;
  for(int i = 0; i < N; ++i) {
    int a; cin >> a; A[i] = make_pair(a, i);
  }
  sort(A, A + N);
  for(int i = 0; i < N / 2; ++i) {
    S[A[i].second] = true;
  }
  for(int i = 0; i < N; ++i) {
    cout << (S[i] ?  A[N / 2].first : A[N / 2 - 1].first) << endl;
  }
  return 0;
}
