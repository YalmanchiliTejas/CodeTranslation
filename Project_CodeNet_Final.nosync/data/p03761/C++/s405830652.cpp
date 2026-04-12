#include <iostream>

using namespace std;

const int INF = 2147483647;

template<class T>
bool chmin(T &a, const T &b) { return b < a && (a = b, 1); }

int main() {
  int n, map[26];
  cin >> n;
  for (int &i : map) i = INF;

  for (int i = 0; i < n; ++i) {
    int _map[26];
    for (int &j : _map) j = 0;
    string s;
    cin >> s;
    for (const char &c : s) _map[c - 'a']++;
    for (int j = 0; j < 26; ++j) chmin(map[j], _map[j]);
  }

  for (int i = 0; i < 26; ++i) {
    char c = 'a' + i;
    for (int j = 0; j < map[i]; ++j) cout << c;
  }
  cout << endl;
}
