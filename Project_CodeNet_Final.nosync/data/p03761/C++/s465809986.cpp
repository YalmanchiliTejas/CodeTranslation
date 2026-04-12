#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  string intersection;
  for (char c = 'a'; c <= 'z'; c++)
    for (int i = 0; i < 50; ++i)
      intersection.push_back(c);

  rep(i,0,n-1) {
    cin >> s;
    sort(s.begin(), s.end());
    string t;
    set_intersection(
      s.begin(), s.end(),
      intersection.begin(), intersection.end(),
      std::back_inserter(t)
    );
    intersection = t;
  }

  for (char c : intersection) cout << c;
  cout << endl;
  return 0;
}
