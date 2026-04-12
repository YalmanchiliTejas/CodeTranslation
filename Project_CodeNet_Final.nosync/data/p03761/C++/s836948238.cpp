#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 30;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  cout << "}";
  return os;
}

// ====================================================================

int main() {
  int n;
  cin >> n;
  vector<vector<int> > v(n, vector<int>(26));  // それぞれの文字列に、アルファベットがでてきた回数
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      v[i][s[j] - 'a']++;
    }
  }

  for (int i = 0; i < 26; i++) {
    int cou = 100;
    for (int y = 0; y < n; y++) {
      cou = min(cou, v[y][i]);
    }

    // 文字を出力
    for (int j = 0; j < cou; j++) {
      cout << (char)(i + 'a');
    }
  }
  cout << endl;
}
