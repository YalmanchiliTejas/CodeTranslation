#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < s.size() -1; i++) {
    if (s[i] != s[i+1]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
