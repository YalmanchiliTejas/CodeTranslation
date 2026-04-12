#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  vector<vector<int>> cnt(n, vector<int>(26,0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i].size(); j++) cnt[i][s[i][j] - 'a']++;
  }
  string res = "";
  for (int i = 0; i < 26; i++) {
    int d = 100000;
    for (int j = 0; j < n; j++) {
      d = min(d, cnt[j][i]);
    }
    while (d--) res += 'a' + i;
  }
  cout << res << endl;
  return 0;
} 