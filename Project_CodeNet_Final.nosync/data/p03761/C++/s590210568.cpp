#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s;
  int alp[n][26];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 26; j++) {
      alp[i][j] = 0;
    }
  }

  for(int i = 0; i < n; i++) {
    string t;
    cin >> t;
    for(int j = 0; j < t.size(); j++) {
        //cout << t[j]-'a' << endl;
        //cout << t[j] << endl;
        alp[i][t[j]-'a']++;
    }
    s.push_back(t);
  }

  string ans = "";
  int alp_num[26];
  for(int i = 0; i < 26; i++) alp_num[i] = alp[0][i];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 26; j++) {
      alp_num[j] = min(alp_num[j], alp[i][j]);
      //cout << alp_num[j] << " ";
    }
    /*
    cout << endl;
    for(int j = 0; j < 26; j++) {
      cout << alp[i][j] << " ";
    }
    cout << endl;
    */
  }

  for(int i = 0; i < 26; i++) {
    if(alp_num[i] != 0) {
      for(int j = 0; j < alp_num[i]; j++) {
        ans += (i+'a');
      }
    }
  }
  cout << ans << endl;
/*
  int p = s.size();
  for(int i = 0; i < 26; i++) alp[i] = 0;
  for(int i = 0; i < p; i++) {
    for(int j = 0; j < s[i].size(); j++) {
      alp[s[j]]++;
    }
  }
  */
  return 0;
}
