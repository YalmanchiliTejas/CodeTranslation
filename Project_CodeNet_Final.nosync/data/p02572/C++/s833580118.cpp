#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >> N;
  
  int64_t a = 0;
  int64_t s = 0;
  int64_t s2 = 0;
  for (int i = 0; i < N; i++) {
    cin >> a;
    s = (s+a*s2)%1000000007;
    s2 = (s2+a)%1000000007;
  }

  cout << s << endl;    

return 0;
}      