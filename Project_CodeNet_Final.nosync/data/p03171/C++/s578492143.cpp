#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int64_t point(int64_t l, int64_t r, vector<int64_t> &D, int64_t n, vector<int64_t> &A, int64_t mm) {
  if (D[l*n + r] != mm) {
    return D[l*n + r];
    }
  else {
    if ((r-l+1)%2 == n%2) {
      D[l*n + r] = max(point(l, r-1, D, n, A, mm) + A[r], point(l+1, r, D, n, A, mm) + A[l]);
    }
    else {
      D[l*n + r] = min(point(l, r-1, D, n, A, mm) - A[r], point(l+1, r, D, n, A, mm) - A[l]);
    }
    return D[l*n + r];
  }
}

int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> A(n);
  for (int i=0; i<n; i++) {
    cin >> A[i];
  }
  
  int64_t mm = pow(10, 14);
  int64_t f = 1;
  if (n%2 == 0) {f = -1;}

  vector<int64_t> D(pow(n, 2), mm);
  for (int i=0; i<n; i++) {
    D[i*n + i] = f * A[i];
  }


  cout << point(0, n-1, D, n, A, mm) << endl;
}