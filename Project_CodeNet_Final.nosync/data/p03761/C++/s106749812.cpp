// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

string t = "abcdefghijklmnopqrstuvwxyz";
int main() {
  assert(t.size() == 26);
  int n; cin >> n;
  set<char> S;
  map<char, int> M;
  string s; cin >> s;
  for (auto c: s) M[c]++;
  
  loop(i,1,n) {
    cin >> s;
    map<char, int> M2;
    for (auto c: s) M2[c]++;
    for (auto c: t) M[c] = min(M[c], M2[c]);
  }
  s = "";
  for (auto m: M) {
    loop(i,0,m.second) s += m.first;
  }
  sort(s.begin(), s.end());
  cout << s << endl;
  return 0;
}
