#include<bits/stdc++.h>
using namespace std;

int N, K;
string S;

int main() {
  cin >> N >> S >> K;

  char p = S[K - 1];

  for (int i = 0; i < N ; ++i) {
    if (S[i] != p) S[i] = '*';
  }
  cout << S << endl;
}
