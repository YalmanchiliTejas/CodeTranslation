#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  int i;
  int A=1;
  int H[N];
  for (i=1; i<=N; ++i) {
    cin >> H[i];
  }
  int HM=H[1];
  for (i=1; i<N; ++i) {
    if (HM <= H[i+1]) {
      HM = H[i+1];
      A = A+1;
    }
  }
  cout << A << endl;
}