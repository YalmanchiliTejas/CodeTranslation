#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int x;
  cin >> x;
  
  if (x >= -40 && x <= 29) {
    cout << "No" << endl;
  }

  if (x >= 30) {
    cout << "Yes" << endl;
  }
}