#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
  string s;
  cin >> s;

  string ans = "No";
  for (int i = 1; i < s.size(); i ++) {
    if (s[i-1] == 'A' && s[i] == 'C') ans = "Yes";
  }

  cout << ans << endl;
}