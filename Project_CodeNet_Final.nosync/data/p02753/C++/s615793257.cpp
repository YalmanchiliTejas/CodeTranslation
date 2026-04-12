#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_s(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
using ll = long long;

int main() {
  string S;
  cin >> S;
  if (S[0] != S[1] || S[0] != S[2] || S[1] != S[2]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
