#include<bits/stdc++.h>
using namespace std;

signed main() {
  int n;
  string s;
  cin >> n;
  vector<map<char, int>> cnt(n);
  map<char, int> mini;
  
  for (int i = 0; i < n; ++i) {
  	for (char alpha = 'a'; alpha <= 'z'; alpha++) {
      cnt[i][alpha] = 0;
  	}
  }
  
  for (char alpha = 'a'; alpha <= 'z'; alpha++) {
    mini[alpha] = 1000000;
  }
  
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      cnt[i][s[j]]++;
    }
  }
  
  for (char alpha = 'a'; alpha <= 'z'; alpha++) {
    for (int i = 0; i < n; ++i) {
      mini[alpha] = min(mini[alpha], cnt[i][alpha]);
    }
  }
  
  for (char alpha = 'a'; alpha <= 'z'; alpha++) {
    while (mini[alpha] > 0) {
      cout << alpha;
      mini[alpha]--;
    }
  }
  cout << endl;
}