#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<char> S(N);
  for (int i=0; i<N; i++) {
    cin >> S[i];
  }
  
  int K;
  cin >> K;
  
  char fix = S[K-1];
  
  for (int i=0; i<N; i++) {
    if (S[i] != fix) S[i] = '*';
  }
  
  for (int i=0; i<N; i++) {
    cout << S[i];
    if (i == N-1) cout << endl;
  }
  
}