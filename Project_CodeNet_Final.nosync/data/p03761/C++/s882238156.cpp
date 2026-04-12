#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++) cin >> S[i];
  
  vector<int> a(26,100);
  for (int i = 0; i < n; i++) {
    vector<int> count(26,0);
    for (int j = 0; j < S[i].size(); j++) {
      count[S[i][j]-'a']++;
    }
    for (int j = 0; j < 26; j++) {
      a[j] = min(a[j],count[j]);
    }
  }
  string s;
  for (int i = 0; i < 26; i++) {
    while (a[i] > 0) {
      s = s + char(i + 'a');
      a[i]--;
    }
  }
  
  cout << s << endl;
}
