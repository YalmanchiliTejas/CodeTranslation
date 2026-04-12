#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  string S;
  int K;
  cin >> N >> S >> K;
  char t = S[K - 1];
  for(int i = 0; i < S.size(); i++) {
    if(S[i] != t) { S[i] = '*'; }
  }
  cout << S << endl;

  return 0;
}