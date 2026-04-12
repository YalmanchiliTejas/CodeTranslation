#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

string conv1(string str) {
  static map<char, string> d;
  d['A'] = "00000";
  d['B'] = "00001";
  d['C'] = "00010";
  d['D'] = "00011";
  d['E'] = "00100";
  d['F'] = "00101";
  d['G'] = "00110";
  d['H'] = "00111";
  d['I'] = "01000";
  d['J'] = "01001";
  d['K'] = "01010";
  d['L'] = "01011";
  d['M'] = "01100";
  d['N'] = "01101";
  d['O'] = "01110";
  d['P'] = "01111";
  d['Q'] = "10000";
  d['R'] = "10001";
  d['S'] = "10010";
  d['T'] = "10011";
  d['U'] = "10100";
  d['V'] = "10101";
  d['W'] = "10110";
  d['X'] = "10111";
  d['Y'] = "11000";
  d['Z'] = "11001";
  d[' '] = "11010";
  d['.'] = "11011";
  d[','] = "11100";
  d['-'] = "11101";
  d['\''] = "11110";
  d['?'] = "11111";

  string res = "";
  for(int i = 0; i < str.length(); ++i) {
    res += d[str[i]];
  }
  return res;
}

bool isAll0(string str) {
  if(str.empty()) return true;
  for(int i = 0; i < str.length(); ++i) if(str[i] != '0') return false;
  return true;
}

string conv2(string &base, int pos) {
  static map<string, char> d;
  d["101"] = ' ';
  d["000000"] = '\'';
  d["000011"] = ',';
  d["10010001"] = '-';
  d["010001"] = '.';
  d["000001"] = '?';
  d["100101"] = 'A';
  d["10011010"] = 'B';
  d["0101"] = 'C';
  d["0001"] = 'D';
  d["110"] = 'E';
  d["01001"] = 'F';
  d["10011011"] = 'G';
  d["010000"] = 'H';
  d["0111"] = 'I';
  d["10011000"] = 'J';
  d["0110"] = 'K';
  d["00100"] = 'L';
  d["10011001"] = 'M';
  d["10011110"] = 'N';
  d["00101"] = 'O';
  d["111"] = 'P';
  d["10011111"] = 'Q';
  d["1000"] = 'R';
  d["00110"] = 'S';
  d["00111"] = 'T';
  d["10011100"] = 'U';
  d["10011101"] = 'V';
  d["000010"] = 'W';
  d["10010010"] = 'X';
  d["10010011"] = 'Y';
  d["10010000"] = 'Z';

  string str = "";
  int s = 0;
  int e = 3;
  while(e <= base.length()) {
    string tmp = base.substr(s, e-s);
    if(d.find(tmp) != d.end()) {
      str += d[tmp];
      s = e;
      e += 3;
    } else {
      ++e;
    }
  }
  if(isAll0(base.substr(s))) return str;
  return "";
}
/*
string conv2(string &base, int pos, string str) {
  static map<string, char> d;
  d["101"] = ' ';
  d["000000"] = '\'';
  d["000011"] = ',';
  d["10010001"] = '-';
  d["010001"] = '.';
  d["000001"] = '?';
  d["100101"] = 'A';
  d["10011010"] = 'B';
  d["0101"] = 'C';
  d["0001"] = 'D';
  d["110"] = 'E';
  d["01001"] = 'F';
  d["10011011"] = 'G';
  d["010000"] = 'H';
  d["0111"] = 'I';
  d["10011000"] = 'J';
  d["0110"] = 'K';
  d["00100"] = 'L';
  d["10011001"] = 'M';
  d["10011110"] = 'N';
  d["00101"] = 'O';
  d["111"] = 'P';
  d["10011111"] = 'Q';
  d["1000"] = 'R';
  d["00110"] = 'S';
  d["00111"] = 'T';
  d["10011100"] = 'U';
  d["10011101"] = 'V';
  d["000010"] = 'W';
  d["10010010"] = 'X';
  d["10010011"] = 'Y';
  d["10010000"] = 'Z';

  if(isAll0(base.substr(pos))) return str;

  int s = pos;
  for(pos += 3; pos <= base.length(); ++pos) {
    string tmp = base.substr(s, pos-s);
    if(d.find(tmp) != d.end()) {
      string res = conv2(base, pos, str+d[tmp]);
      if(!res.empty()) return res;
    }
  }
  return "";
}
*/
void solve(string &str) {
  string base = conv1(str);
  cout <<  conv2(base, 0) << endl;
}

main() {
  string str;
  while(getline(cin, str)) solve(str);
}