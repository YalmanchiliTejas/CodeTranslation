#include <bits/stdc++.h>
using namespace std;

void prians(bool answer) {
  if(answer)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int r, g, b;

int main() {
  cin >> r >> g >> b;
  prians((g * 10 + b) % 4 == 0);
  return 0;
}