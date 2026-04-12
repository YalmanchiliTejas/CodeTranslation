#include <bits/stdc++.h>
#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long

using namespace std;

const int MOD = 1000000007;

int main() {
  int n;
  scanf("%d", &n);

  int r = 0;
  int highest = 0;
  for (int i = 0; i < n; i++) {
    int h;
    scanf("%d", &h);

    if (h >= highest) {
      r += 1;
      highest = h;
    }
  }

  cout << r << endl;
}
