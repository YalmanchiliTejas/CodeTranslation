#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#include <iostream>
#include<map>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
if((10 * g + b) % 4 == 0) cout << "YES" << endl;
else cout << "NO" << endl;
}