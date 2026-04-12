#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

ll l[51];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  ll ret = 0;
  sort(l, l+n);
  int d = 55;
  while(d > 0) {
    bool upd = false;
    for(int i = 0; i < n; i++) {
      ll dec = n * (1LL << d);
      if(l[i] - dec >= n) {
        upd = true;
        ret += (1LL << d);
        l[i] -= dec;
        for(int j = 0; j < n; j++) {
          if(i == j) continue;
          l[j] += (1LL << d);
        }
      }
      sort(l, l+n);
    }
    if(!upd) d--;
  }
  while(l[n-1] >= n) {
    ret++;
    l[n-1] -= n;
    for(int i = 0; i < n-1; i++) l[i]++;
    sort(l, l+n);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}
