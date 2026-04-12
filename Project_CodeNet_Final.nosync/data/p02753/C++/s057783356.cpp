#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  string s;
  cin >> s;
  if (s == "BBB" || s == "AAA") cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}