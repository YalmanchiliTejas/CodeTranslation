#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, T, E; cin >> N >> T >> E;
  vector<int> X(N);
  for(int i=0; i<N; i++) cin >> X[i];

  int lb = T - E, ub = T + E;
  for(int i=0; i<N; i++) {
    for(int x=1; x*X[i]<=ub; x++) {
      int v = x * X[i];
      if(lb <= v and v <= ub) {
        cout << i + 1 << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

