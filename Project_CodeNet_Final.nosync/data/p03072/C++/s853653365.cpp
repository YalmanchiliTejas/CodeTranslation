#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> height(N);
  for (int i=0; i<N; ++i) {
    cin >> height[i];
  }
  
  int ans=0, var=0;
  for (int i=0; i<N; ++i) {
    var = 1;
    for (int j=0; j<=i; ++j) {
      if (height[i] < height[j]) {
        var = 0;
      }
    }
    ans += var;
  }
  
  cout << ans << endl;
  return 0;
}





