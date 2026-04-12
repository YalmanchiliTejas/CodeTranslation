#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

void showes(vector<char> ans) {
  for (auto itr : ans) {
    cout << itr;
  } END;
}

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<char> applyed(2);
  applyed[0] = 'S';
  applyed[1] = 'W';
  s.pb(s[0]);
  s.pb(s[1]);

  for (int bit = 0; bit < (1 << 2); ++bit) {
    // 0 -> 羊, 1 -> 狼
    vector<int> now(n+2);
    vector<char> ans(n+2);
    for (int j = 0; j < 2; ++j) {
      now[j] = (bit >> j) & 1;
      ans[j] = applyed[now[j]];
    }

    int last = now.front();
    for (int i = 1; i <= n; ++i) {
      if (now[i] == 0) {
        // 羊 phase
        if (s[i] == 'o') {
          now[i+1] = now[i-1];
        } else {
          now[i+1] = (now[i-1] == 0) ? 1 : 0;
        }
      } else {
        // 狼 phase
        if (s[i] == 'o') {
          now[i+1] = (now[i-1] == 0) ? 1 : 0;
        } else {
          now[i+1] = now[i-1];
        }
      }
      ans[i+1] = applyed[now[i+1]];
    }
    if (now[n+1] == now[1] and now[0] == now[n]) {
      ans.pop_back();
      ans.pop_back();
      showes(ans);
      return 0;
    }
  }

  cout << -1 << endl;
}
