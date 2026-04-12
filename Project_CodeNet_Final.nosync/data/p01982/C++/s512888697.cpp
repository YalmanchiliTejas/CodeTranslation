#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
  int n, l, r;
  while(cin >> n >> l >> r, n + l + r) {
    vector<int> A(n);
    REP (i, 0, n) {
      cin >> A[i];
    }
    int ans = 0;
    REP (i, l, r + 1) {
      bool ok = false;
      REP (j, 0, n) {
	if (i % A[j] == 0) {
	  ok = true;
	  if ((j + 1) % 2 == 1) {
	    ans++;
	    //cout << i << endl;
	  }
	  break;
	}
      }
      if ((!ok) && n % 2 == 0) {
	//cout << "!" << ok << " " << n % 2 << " " << i << endl;
	ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

