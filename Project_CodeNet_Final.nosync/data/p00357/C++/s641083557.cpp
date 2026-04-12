#include <bits/stdc++.h>

using namespace std;
using LL = long long int;

const int MAX_N = 300005;

int N;
int D[MAX_N];
bool DUsed[MAX_N];

int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> D[i];
  }

  int M = 0;
  for(int i = 0; i < N; i++) {
    if(i <= M) {
      M = max(M, i + D[i]/10);
    } else {
      cout << "no" << endl;
      return 0;
    }
  }

  M = N-1;
  for(int i = N-1; 0 <= i; i--) {
    if(i >= M) {
      M = min(M, i-D[i]/10);
    } else {
      cout << "no" << endl;
      return 0;
    }
  }

  cout << "yes" << endl;

  return 0;
}