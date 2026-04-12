#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  int big = 0;
  vector<int> nn(N,0);
  for (int i=0; i<N; i++) {
    cin >> nn[i];
    big = max(big,nn[i]);
    if (nn[i] >= big) {
      ans++;
    }
  }
  
  cout << ans << endl;
}