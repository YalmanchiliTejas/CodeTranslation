#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<utility>

using namespace std;


const int MAXL = 301;


pair<string, int> getLCS(string s1, string s2) {
  int L1 = (int) s1.size(), L2 = (int) s2.size();
  s1 = " " + s1;
  s2 = " " + s2;
  vector<vector<int> > D(s1.size(), vector<int>(s2.size(), 0));
  vector<vector<string> > common_subs(s1.size(), vector<string>(s2.size(), ""));

  for (size_t i = 1; i < s1.size(); ++i) {
    for (size_t j = 1; j < s2.size(); ++j) {
      if (s1[i] == s2[j]) {
        D[i][j] = D[i-1][j-1] + 1;
        common_subs[i][j] = common_subs[i-1][j-1] + s1[i];
      }
      else {
        D[i][j] = max(D[i-1][j], D[i][j-1]);
        if (D[i-1][j] > D[i][j-1]) common_subs[i][j] = common_subs[i-1][j];
        else common_subs[i][j] = common_subs[i][j-1];
      }
    }
  }

  return make_pair(common_subs[L1][L2], D[L1][L2]);
}


void solve(string s) {
  int len = (int) s.size();
  
  string ans = "";
  int max_l = 0;
  for (int k = 1; k < len; ++k) {
    string sub1 = s.substr(0, k);
    string sub2 = s.substr(k, len-k);

    if ((int) min(sub1.size(), sub2.size()) <= max_l) continue;

    pair<string, int> res;
    res = getLCS(sub1, sub2);
    if (res.second > max_l) {
      ans = res.first;
      max_l = res.second;
    }
  }

  printf("%s\n", ans.c_str());
}


int main() {
  char s[MAXL];

  while (scanf("%s", s) != EOF) {
    if (strcmp(s, "#END") == 0) break;

    solve(s);
  }
  return 0;
}

