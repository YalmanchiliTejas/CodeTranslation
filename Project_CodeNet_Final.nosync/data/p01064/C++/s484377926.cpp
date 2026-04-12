#include<bits/stdc++.h>
using namespace std;


int main()
{
  int N, M, a, d, X[200000], Y[200000], Z[200000], K;
  cin >> N;
  cin >> a >> d;
  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> X[i] >> Y[i] >> Z[i];
  }
  cin >> K;
  
  for(int i = M - 1; i >= 0; i--) {
    if(X[i] == 0) {
      if(Y[i] <= K && K <= Z[i]) {
        K = Y[i] + Z[i] - K;
      }
    }
  }

  long long value = a + (K - 1) * d;

  for(int i = 0; i < M; i++) {
    if(X[i] == 0) {
      if(Y[i] <= K && K <= Z[i]) {
        K = Y[i] + Z[i] - K;
      }
    } else if(X[i] == 1) {
      if(Y[i] <= K && K <= Z[i]) {
        ++value;
      }
    } else {
      if(Y[i] <= K && K <= Z[i]) {
        value /= 2;
      }
    }
  }
  cout << value << endl;
}