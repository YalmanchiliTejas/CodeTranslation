#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, K; cin >> N;
  vector<char> S(N);
  for (int i=0; i<N; i++) cin >> S[i];
  cin >> K;

  char c;
  c= S[K-1];
  for (int i=0; i<N; i++) if (S[i] != c) S[i]='*';
  for (int i=0; i<N; i++) cout << S[i];
  cout << "\n";
}