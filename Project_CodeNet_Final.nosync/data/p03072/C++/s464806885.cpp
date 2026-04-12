#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int h[N];
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  
  int ans = 1;
  for (int i = 1; i < N; i++) {
    bool ok = true;
    for (int j = 0; j < i; j++) {
      if (h[j] > h[i]) {ok = false;}
    }
    if (ok) {ans++;}
  }
  
  cout << ans << endl;
}
      
