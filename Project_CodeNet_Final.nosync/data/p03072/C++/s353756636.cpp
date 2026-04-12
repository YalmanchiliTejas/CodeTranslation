#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> height(n);
  for (int i = 0; i < height.size(); i++) {
    cin >> height.at(i);
  }
  int ans = 0;
  int max = height.at(0);
  for (int x : height) {
    if (x >= max) {
      ans++;
      max = x;
    }
  }
  cout << ans << endl;
}
