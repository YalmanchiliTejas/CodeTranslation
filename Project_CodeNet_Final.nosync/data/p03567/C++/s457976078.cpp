#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n, k;
  n=S.size();
  k=0;
  for (int i=0; i<n-1; i++) {
    if (S.at(i)=='A' && S.at(i+1)=='C') {
      k=k+1;
    }
  }
  if (k>=1) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
