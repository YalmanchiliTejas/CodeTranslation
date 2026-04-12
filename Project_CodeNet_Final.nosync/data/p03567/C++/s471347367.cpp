#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  string S; cin >> S;
  string ans = "No";
  REP(i, S.size() - 1) {
    if(S[i] == 'A' && S[i + 1] == 'C') ans = "Yes";
  }

  cout << ans << endl;
}