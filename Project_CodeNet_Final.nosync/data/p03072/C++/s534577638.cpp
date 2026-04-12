#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int prev;
  cin >> prev;
  int i = 1;
  for ( int j = 0; j < n - 1; j++ ) {
    int now;
    cin >> now;
    if ( now >= prev ) {
      i++;
      prev = now;
    }
  }
  cout << i << endl;
  return 0;
}