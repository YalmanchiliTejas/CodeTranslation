#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  int N, K; string S; cin >> N >> S >> K;
  K--;

  for (int i = 0; i < N; ++i) {
    if (S[K] != S[i]) {
      S[i] = '*';
    }
  }

  cout << S << endl;
}