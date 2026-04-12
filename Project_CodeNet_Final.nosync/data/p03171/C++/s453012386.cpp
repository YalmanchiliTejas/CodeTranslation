#include <iostream>
#include <vector>

using namespace std;
int main() {
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i=0; i<N; i++) cin >> a[i];

  // v(i,j) = value at the left position is i and right position is j
  // initially, i=0 and j=N-1
  vector< vector<long long> > v(N);
  for (int i=0; i<N; i++) v[i].resize(N);

  /*
  For first mover,
  v(i,j) = max { v(i+1, j) + a(i), v(i, j-1) + a(j) }  if i < j
         = a(i)                                        if i = j
  For second mover,
  v(i,j) = min { v(i+1, j) - a(i), v(i, j-1) - a(j) }  if i < j
         = a(i)                                        if i = j
  */
  for (int i=N-1; i >= 0; i--) {
    for (int j=i; j < N; j++) {
      // when i + j = N-1 mod 2, first player's turn.
      bool first = ((i + j) % 2) == ((N - 1) % 2);
      if (i == j) {
        v[i][j] = first ? a[i] : -a[i];
      } else {
        if (first) {
          v[i][j] = max(v[i+1][j] + a[i], v[i][j-1] + a[j]);
        } else {
          v[i][j] = min(v[i+1][j] - a[i], v[i][j-1] - a[j]);
        }
      }
    }
  }

  /*
  for (int i=0; i < N; i++) {
    for (int j=0; j < N; j++) {
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }
  */
  
  cout << v[0][N-1] << "\n";
  return 0;
}
