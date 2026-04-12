/*
　　　　　　 ＿＿
　　　　　／＞　　 フ
　　　　　|   _　 _l
　 　　　／` ミ＿x ノ   Zzz..
　　 　 /　 　 　 |   コード見ちゃだめ！！
　　　 /　 ヽ　　  ﾉ
　 　 │　　|　|  |
　／￣|　　 |　|  |
　| (￣ヽ＿_ヽ_)_ _)
　＼二つ
*/

#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define REP(i, n) for (int i = 0; i < n; i++)
const int MOD = 1e9 + 7;
typedef long long ll;
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<int> a(123, 100);
  vector<int> aa(123, 0);

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      aa[(int)s[j]]++;
    }
    for (int j = 97; j < 123; j++) {
      if (a[j] > aa[j]) a[j] = aa[j];
      aa[j] = 0;
    }
  }
  string s = "";
  for (int i = 97; i < 123; i++) {
    if (a[i] == 100) continue;
    for (int j = 0; j < a[i]; j++) {
      s = s + (char)i;
    }
  }
  cout << s << endl;
}