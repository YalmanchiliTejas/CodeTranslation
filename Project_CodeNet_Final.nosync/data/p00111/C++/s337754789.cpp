#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

map<char, string> mp;
map<string, char> mp2;
vector<string> v;

void init() {
  mp['A'] = "00000";
  mp['B'] = "00001";
  mp['C'] = "00010";
  mp['D'] = "00011";
  mp['E'] = "00100";
  mp['F'] = "00101";
  mp['G'] = "00110";
  mp['H'] = "00111";
  mp['I'] = "01000";
  mp['J'] = "01001";
  mp['K'] = "01010";
  mp['L'] = "01011";
  mp['M'] = "01100";
  mp['N'] = "01101";
  mp['O'] = "01110";
  mp['P'] = "01111";
  mp['Q'] = "10000";
  mp['R'] = "10001";
  mp['S'] = "10010";
  mp['T'] = "10011";
  mp['U'] = "10100";
  mp['V'] = "10101";
  mp['W'] = "10110";
  mp['X'] = "10111";
  mp['Y'] = "11000";
  mp['Z'] = "11001";
  mp[' '] = "11010";
  mp['.'] = "11011";
  mp[','] = "11100";
  mp['-'] = "11101";
  mp['\''] = "11110";
  mp['?'] = "11111";

  mp2["101"] = ' ';
  mp2["000000"] = '\'';
  mp2["000011"] = ',';
  mp2["10010001"] = '-';
  mp2["010001"] = '.';
  mp2["000001"] = '?';
  mp2["100101"] = 'A';
  mp2["10011010"] = 'B';
  mp2["0101"] = 'C';
  mp2["0001"] = 'D';
  mp2["110"] = 'E';
  mp2["01001"] = 'F';
  mp2["10011011"] = 'G';
  mp2["010000"] = 'H';
  mp2["0111"] = 'I';
  mp2["10011000"] = 'J';
  mp2["0110"] = 'K';
  mp2["00100"] = 'L';
  mp2["10011001"] = 'M';
  mp2["10011110"] = 'N';
  mp2["00101"] = 'O';
  mp2["111"] = 'P';
  mp2["10011111"] = 'Q';
  mp2["1000"] = 'R';
  mp2["00110"] = 'S';
  mp2["00111"] = 'T';
  mp2["10011100"] = 'U';
  mp2["10011101"] = 'V';
  mp2["000010"] = 'W';
  mp2["10010010"] = 'X';
  mp2["10010011"] = 'Y';
  mp2["10010000"] = 'Z';
  
  v.emplace_back("101");
  v.emplace_back("000000");
  v.emplace_back("000011");
  v.emplace_back("10010001");
  v.emplace_back("010001");
  v.emplace_back("000001");
  v.emplace_back("100101");
  v.emplace_back("10011010");
  v.emplace_back("0101");
  v.emplace_back("0001");
  v.emplace_back("110");
  v.emplace_back("01001");
  v.emplace_back("10011011");
  v.emplace_back("010000");
  v.emplace_back("0111");
  v.emplace_back("10011000");
  v.emplace_back("0110");
  v.emplace_back("00100");
  v.emplace_back("10011001");
  v.emplace_back("10011110");
  v.emplace_back("00101");
  v.emplace_back("111");
  v.emplace_back("10011111");
  v.emplace_back("1000");
  v.emplace_back("00110");
  v.emplace_back("00111");
  v.emplace_back("10011100");
  v.emplace_back("10011101");
  v.emplace_back("000010");
  v.emplace_back("10010010");
  v.emplace_back("10010011");
  v.emplace_back("10010000");
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  init();
  string s;
  while (getline(cin, s)) {
    string tmp = "";
    for (int i = 0; i < (int)s.size(); i++) {
      tmp += mp[s[i]];
    }
    s = tmp;
    int pos = 0;
    string ans = "";
    while (true) {
      bool find = false;
      for (int i = 0; i < 32; i++) {
        string t = v[i];
        if (s.substr(pos, t.size()) == t) {
          ans += mp2[t];
          pos += t.size();
          find = true;
        }
      }
      if (!find) break;
    }
    cout << ans << endl;
  }

  return 0;
}
