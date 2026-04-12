#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  vector<string> s(N);
  for (int i = 0; i < N; ++i)
    cin >> s[i];

  map<char, int> m;

  for (int i = 0; i < s[0].size(); ++i) {
    if (m.find(s[0][i]) == m.end())
      m[s[0][i]] = 0;
    ++m[s[0][i]];
  }

  for (int i = 1; i < N; ++i) {
    map<char, int> tmp;
    for (int j = 0; j < s[i].size(); ++j) {
      if (tmp.find(s[i][j]) == tmp.end())
        tmp[s[i][j]] = 0;
      ++tmp[s[i][j]];
    }
    for (map<char, int>::iterator j = m.begin(); j != m.end(); ++j) {
      if (tmp.find(j->first) == tmp.end())
        m[j->first] = 0;
      else
        m[j->first] = min(j->second, tmp[j->first]);
    }
  }

  string ret = "";
  for (map<char, int>::iterator i = m.begin(); i != m.end(); ++i) {
    if (i->second == 0)
      continue;
    for (int j = 0; j < i->second; ++j)
      ret += i->first;
  }

  sort(ret.begin(), ret.end());

  cout << ret << endl;

  return 0;
}