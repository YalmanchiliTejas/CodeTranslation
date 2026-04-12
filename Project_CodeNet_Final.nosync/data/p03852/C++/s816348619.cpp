#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  set<char> s = {'a', 'e', 'i', 'o', 'u'};
  char c;
  cin >> c;
  cout << (s.find(c) == s.end() ? "consonant" : "vowel") << endl;
  return 0;
}
