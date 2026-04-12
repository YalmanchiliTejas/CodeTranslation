#include <bits/stdc++.h>
using namespace std;

class humberger {
  public: 
  vector<long long int> size;
  vector<long long int> pattySize;
  void init() {
    size.resize(51);
    pattySize.resize(51);
    size[0] = 1;
    pattySize[0] = 1;
    for(int i=1;i<51;i++) {
      size[i] = size[i-1] * 2 + 3;
      pattySize[i] = pattySize[i-1] * 2 + 1;
    }
  }
  long long int patty (int level, long long int x) {
    if(level == 0) return (x == 0 ? 0LL : 1LL);
    else {
      if(x == 0 || x == 1) return 0;
      else if(x <= size[level-1] + 1) return patty(level-1, x-1);
      else if(x == size[level-1] + 2) return pattySize[level-1] + 1;
      else if(x <= 2 * size[level-1] + 2) return pattySize[level-1] + 1 + patty(level-1, x - size[level-1] - 2);
      else return 2 * pattySize[level-1] + 1;
    }
  }
};

int main() {
  int N;
  long long int X;
  cin >> N >> X;

  humberger a;
  a.init();

  cout << a.patty(N, X) << endl;
}