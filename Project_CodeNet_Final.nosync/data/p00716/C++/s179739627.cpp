#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int m;
  cin >> m;
  while(m--) {
    int A, y, n;
    cin >> A;
    cin >> y;
    cin >> n;

    int maxv = 0;
    for(int t = 0; t < n; ++t) {
      int mode, q;
      double p;
      cin >> mode >> p >> q;

      int a = A;
      int c = 0;
      for(int i = 0; i < y; ++i) {
	int b = (int)(a * p);
	if(mode) {
	  a = a + b - q;
	} else {
	  a = a - q;
	  c += b;
	}
      }
      maxv = max(maxv, a+c);
    }
    cout<< maxv << endl;
  }
  return 0;
}