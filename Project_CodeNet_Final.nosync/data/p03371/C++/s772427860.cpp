#include <bits/stdc++.h>
using namespace std;

int main() {
  long A,B,C;
  int X,Y;
  cin >> A >> B >> C >> X >> Y;
  long min_p=1000000000;
  for (int c=0;c<=max(X,Y);c++) {
    min_p = min(min_p, A*max(0, (X-c)) + B*max(0, (Y-c)) +2*C*c);
  }
  cout << min_p << endl;
}