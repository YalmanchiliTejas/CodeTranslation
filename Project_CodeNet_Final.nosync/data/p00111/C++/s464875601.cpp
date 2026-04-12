#include <iostream>
#include <string>
#include <map>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);++(i))

string in;
map<char,string> m;
const char cs[32] = {
  ' ', '\'', ',', '-', '.', '?',
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
  'Y', 'Z'
};
const string ss[32] = {
  "101", "000000", "000011", "10010001", "010001", "000001",
  "100101", "10011010", "0101", "0001", "110", "01001", "10011011", "010000",
  "0111", "10011000", "0110", "00100", "10011001", "10011110", "00101", "111",
  "10011111", "1000", "00110", "00111", "10011100", "10011101", "000010",
  "10010010", "10010011", "10010000"
};

void init() {
  // first convert
  m.insert(make_pair('A', "00000"));
  m.insert(make_pair('B', "00001"));
  m.insert(make_pair('C', "00010"));
  m.insert(make_pair('D', "00011"));
  m.insert(make_pair('E', "00100"));
  m.insert(make_pair('F', "00101"));
  m.insert(make_pair('G', "00110"));
  m.insert(make_pair('H', "00111"));
  m.insert(make_pair('I', "01000"));
  m.insert(make_pair('J', "01001"));
  m.insert(make_pair('K', "01010"));
  m.insert(make_pair('L', "01011"));
  m.insert(make_pair('M', "01100"));
  m.insert(make_pair('N', "01101"));
  m.insert(make_pair('O', "01110"));
  m.insert(make_pair('P', "01111"));
  m.insert(make_pair('Q', "10000"));
  m.insert(make_pair('R', "10001"));
  m.insert(make_pair('S', "10010"));
  m.insert(make_pair('T', "10011"));
  m.insert(make_pair('U', "10100"));
  m.insert(make_pair('V', "10101"));
  m.insert(make_pair('W', "10110"));
  m.insert(make_pair('X', "10111"));
  m.insert(make_pair('Y', "11000"));
  m.insert(make_pair('Z', "11001"));
  m.insert(make_pair(' ', "11010"));
  m.insert(make_pair('.', "11011"));
  m.insert(make_pair(',', "11100"));
  m.insert(make_pair('-', "11101"));
  m.insert(make_pair('\'', "11110"));
  m.insert(make_pair('?', "11111"));
}

void solve() {
  string s;
  rep (i,in.size()) s += m[in[i]];
  string ans;

  while (s.size()) {
    bool isChanged = false;
    rep (i,32) {
      if (ss[i].size() > s.size()) continue;
      bool ok = true;
      rep (j,ss[i].size()) if (ss[i][j] != s[j]) ok = false;
      if (!ok) continue;

      string t = " ";
      t[0] = cs[i];
      ans += t;
      isChanged = true;
      s.erase(0, ss[i].size());
      break;
    }
    if (!isChanged) break;
  }
  cout << ans << endl;  
}

int main() {
  init();
  while (getline(cin, in)) solve();
  return 0;
}