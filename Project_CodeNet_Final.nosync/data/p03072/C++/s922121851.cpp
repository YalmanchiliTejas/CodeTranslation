#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> hight(n);
  rep(i,n) cin >> hight[i];

  int cnt = 1;
  int maxh = hight[0];
  for (int i = 1; i < n; i++) {
    if (maxh <= hight[i]) cnt++;
    maxh = max(maxh, hight[i]);
  }

  cout << cnt << endl;
  return 0;
}