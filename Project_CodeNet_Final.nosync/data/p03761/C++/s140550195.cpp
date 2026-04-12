#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, n) for(ll i = 0;i < n;i++)

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  int n;
  cin >> n;
  int dic[50][26] = {};
  rep(i, n) {
    string s;
    cin >> s;
    for (auto&& j : s) {
      dic[i][j-'a']++;
    }
  }

  vector<char> ans;
  rep(i, 26) {
    int cnt = 10000;
    rep(j, n) {
      cnt = min(cnt, dic[j][i]);
    }
    rep(k, cnt) {
      ans.push_back((char)'a'+i);
    }
  }

  for (auto&& i : ans) {
    cout << i;
  }
  cout << endl;
}