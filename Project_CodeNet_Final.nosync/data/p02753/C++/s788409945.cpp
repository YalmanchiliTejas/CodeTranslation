#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;


int main() {
  string s;
  cin >> s;
  if (s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}