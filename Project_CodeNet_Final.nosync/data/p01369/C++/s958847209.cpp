#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()
#define let auto const

int main() {
  set<char> st;
  vector<i64> vec = {
    'q',
    'w',
    'e',
    'r',
    't',
    'a',
    's',
    'd',
    'f',
    'g',
    'z',
    'x',
    'c',
    'v',
    'b',
  };
  for(auto x: vec) st.insert(x);
  string s;
  while(cin >> s, s != "#") {
    i64 ans = 0;
    i64 bf = st.count(s.front());
    for(auto x: s) {
      ans += bf ^ st.count(x);
      bf = st.count(x);
    }
    cout << ans << endl;
  }
}

