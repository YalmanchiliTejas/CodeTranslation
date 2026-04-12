#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  char c; cin >> c;
  string s = "aiueo";
  for(auto e : s) if(c == e) return (cout << "vowel" << endl, 0);
  cout << "consonant" << endl;
}
