#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll N; cin >> N;
  string S; cin >> S;
  ll K; cin >> K;
  char target = S[K-1];
  for (ll j=0; j < S.length(); ++j) {
    cout << (S[j] == target ? target : '*');
  }
  cout << endl;
  return 0;
}
