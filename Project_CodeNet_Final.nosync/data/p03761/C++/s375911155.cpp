#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> strings;
  for (int i=0; i<n; i++) {
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    strings.push_back(str);
  }

  char alpabet = 'a';
  int counts[26];
  for (int i=0; i<26; i++) {
    counts[i] = 0;
  }

  for (int i=0; i<26; i++) {
    int min_count = 50;
    for (int j=0; j<n; j++) {
      int count=0;
      for (int k=0; k<strings[j].size(); k++) {
          if (strings[j][k] == alpabet+i) {
            count++;
          }
      }
      if (count < min_count) {
        counts[i] = count;
        min_count = count;
      }
    }
  }

  string ans;
  for (int i=0; i<26; i++) {
    //cout << counts[i] << endl;
    string s(counts[i], 'a'+i);
    ans += s;
  }

  cout << ans << endl;

  return 0;
}
