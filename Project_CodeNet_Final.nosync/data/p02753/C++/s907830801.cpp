#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main() {

  string S, S1, S2, S3;
  cin >> S;
  S1 = S[0];
  S2 = S[1];
  S3 = S[2];
  
  if (S1 == S2) {
    if (S2 == S3) {
      cout << "No";
    }
    else {
      cout << "Yes";
    }
  }
  else {
    cout << "Yes";
  }
  
}
