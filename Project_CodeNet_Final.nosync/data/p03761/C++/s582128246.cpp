#define MYDEBUG
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <queue>

#ifdef MYDEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x)
#endif
#define ll long long
#define ull unsigned long long
#define eps 1e-14
#define all(x) x.begin(), x.end()
#define umap unordered_map
using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  size_t last = v.size() - 1;
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last)
      out << ",";
  }
  out << "]";
  return out;
}

void solve() {

}

int char_count(char c, string s) {
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == c)
      cnt++;
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  string st[n];
  int cnt[n]['z' - 'a' + 1];
  for (int i = 0; i < n; ++i) {
    cin >> st[i];
  }
  //a-zのカウントを取る
  //cnt[]['a']の最小値+cnt[]['b']+....
  for (int i = 0; i < n; ++i) {
    for (char j = 'a'; j <= 'z'; ++j) {
      cnt[i][j - 'a'] = char_count(j, st[i]);
    }
  }
  for (int i = 0; i < 'z' - 'a' + 1; ++i) {
    int mini = 1000;
    for (int j = 0; j < n; ++j) {
      mini = min(mini, cnt[j][i]);
    }
    if (mini > 0) {
      for (int k = 0; k < mini; ++k) {
        cout << (char) (i + 'a');
      }
    }
  }
  cout << endl;
}

