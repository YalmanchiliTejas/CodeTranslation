#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M=0;
  cin >> N;
  vector<int> V(N);
  for (int i=0; i<N; i++) {
    cin >> V[i];
  }
  
  int C=0;
  for (int i=0; i<N; i++) {
    if (M<=V[i]) {
      C++;
      M=V[i];
    }
  }
  cout << C << endl;
  
}
