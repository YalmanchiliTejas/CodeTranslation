#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
  int n,cnt = 1;
  cin >> n;
  vector<int>height(n);
  for (int i = 0; i < n; i++) {
    cin >> height.at(i);
  }
  for (int i = 1; i < n; i++) {
    bool check = 1;
    for (int j = 0; j < i; j++) {
      if (height.at(i) < height.at(j)) {
        check = 0;
      }
    }
    if (check == 1) cnt ++;
  }
  cout << cnt;
}