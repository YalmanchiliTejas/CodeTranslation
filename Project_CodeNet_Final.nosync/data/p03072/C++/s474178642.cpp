#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, _max = -1, ans = 0;
  
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    int _in;
    
    cin >> _in;
    
    if (_max <= _in) {
      ans++;
    }
    _max = max(_max, _in);
  }
  
  cout << ans << endl;
  return 0;
}