#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;
  char k = S.at(K-1);
  
  string ans;
  
  for (int i = 0; i < N; i++) {
    if (!(S.at(i) == k)) {
      ans = ans + '*';
    }
    else {
      ans = ans + k;
    }
  }
  cout << ans << endl;
}