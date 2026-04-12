#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cout << "DEBUG>" << #x << ":" << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)

int main() {
  int X;
  cin >> X;
  if(X == 7 || X == 5 || X == 3) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
