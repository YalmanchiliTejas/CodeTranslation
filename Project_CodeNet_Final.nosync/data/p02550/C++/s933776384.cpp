#include <bits/stdc++.h>
using namespace std; 

int main() {
  
  int64_t N, X, M;
  cin >> N >> X >> M;
  
  vector<int64_t> Xlist(200001,0);
  Xlist.at(0) = X;
  
  bool lcheck = false;
  int d = 0;
  int64_t m = 0;
  int i2 = 0;
  
  for (int i = 1; i < N; i++) {
    X = X*X%M;
    Xlist.at(i) = X;
    if (lcheck) {
      if ((N-i-1)%d == 0) {
        m = (N-i-1)/d;
        i2 = i;
        goto end;
      }
    }
    else {
      for (int j = 0; j < i; j++) {
        if (Xlist.at(i) == Xlist.at(j)) {
          d = i-j;
          lcheck = true;
          break;
        }
      }
    }
  }
  
  end:
  
  int64_t S = 0;
  int64_t S2 = 0;
  
  if (m == 0) {
    for (int i = 0; i < N; i++) {
      S = S+Xlist.at(i);
    }
  }
  else {
    for (int i = 0; i < i2+1-d; i++) {
      S = S+Xlist.at(i);
    }
    for (int i = i2+1-d; i < i2+1; i++) {
      S2 = S2+Xlist.at(i);
    }
    S2 *= m+1;
    S += S2;
  }
  
  
  cout << S << endl;

return 0;
}