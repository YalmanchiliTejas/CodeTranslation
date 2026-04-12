// C++ 14
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int h, w; cin >> h >> w;
  vector<string> A(h);
  loop(i,0,h) cin >> A[i];
  vector<bool> deleteH(h, false);
  vector<bool> deleteW(w, false);
  loop(i,0,h) {
    bool del = true;
    loop(j,0,w) {
      del &= A[i][j] == '.';
    }
    deleteH[i] = del;
  }
  loop(j,0,w) {
    bool del = true;
    loop(i,0,h) {
      del &= A[i][j] == '.';
    }
    deleteW[j] = del;
  }

  loop(i,0,h) {
    if (deleteH[i]) continue;
    loop(j,0,w) {
      if (deleteW[j]) continue;
      cout << A[i][j];
    }
    cout << endl;
  }

  return 0;
}
