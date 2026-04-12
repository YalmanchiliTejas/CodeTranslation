#include <bits/stdc++.h>
using namespace std;

void prians(bool answer) {
  if(answer)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int x;

int main() {
  cin >> x;
  prians(x == 3 || x == 5 || x == 7);
  return 0;
}