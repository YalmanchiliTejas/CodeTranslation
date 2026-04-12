#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<char,int> mode, as;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    int k = s.size();
    if (i == 0) {
      for (int j = 0; j < k; j++) mode[s[j]] += 1;
      continue;
    }
    for (int j = 0; j < k; j++) as[s[j]] += 1;
    for (auto m : mode) mode[m.first] = min(m.second,as[m.first]);
    as.clear();
  }
  
  string s;
  for (auto m : mode) {
    for (int i = 0; i < m.second; i++) {
      s += m.first;
    }
  }
  sort(s.begin(),s.end());
  cout << s << endl;
}