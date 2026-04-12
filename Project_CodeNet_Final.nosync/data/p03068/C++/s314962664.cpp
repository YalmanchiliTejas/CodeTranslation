#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int n,k;
  string s;
  cin >> n;
  cin >> s;
  cin >> k;

  char x = s[k-1];
  rep(i,n) if(s[i] != x) s[i] = '*';
  cout << s << endl;
  return 0;
}