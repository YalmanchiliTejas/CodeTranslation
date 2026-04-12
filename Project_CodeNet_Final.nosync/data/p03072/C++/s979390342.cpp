#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, ans, l;
  cin >> N;
  ans=1;
  vector<int> H(N);
  for (int i=0; i<N; i++) {
    cin >> H[i];
  }
  if (N>=2) {
    for (int j=1; j<N; j++) {
      l=0;
      for (int k=0; k<j; k++) {
        if (H[k]<=H[j]) {
          l=l+1;
        }
      }
      if (l==j) {
        ans=ans+1;
      }
    }
  }
  cout << ans << endl;
}
