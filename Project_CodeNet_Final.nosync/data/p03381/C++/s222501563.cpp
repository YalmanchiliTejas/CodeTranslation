#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, X[200000];

  cin >> N;
  vector< int > vs;
  for(int i = 0; i < N; i++) {
    cin >> X[i];
    vs.emplace_back(X[i]);
  }
  sort(begin(vs), end(vs));
  int mex1 = vs[(N - 1) / 2];
  int mex2 = vs[(N + 1) / 2];
  for(int i = 0; i < N; i++) {
    if(X[i] <= mex1) cout << mex2 << endl;
    else cout << mex1 << endl;
  }
}
