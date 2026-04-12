#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define F first
#define S second
#define INF 1 << 30

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

string str;

string encode(string code){
  map<char, string> m;
  m['A'] = "00000";
  m['B'] = "00001";
  m['C'] = "00010";
  m['D'] = "00011";
  m['E'] = "00100";
  m['F'] = "00101";
  m['G'] = "00110";
  m['H'] = "00111";
  m['I'] = "01000";
  m['J'] = "01001";
  m['K'] = "01010";
  m['L'] = "01011";
  m['M'] = "01100";
  m['N'] = "01101";
  m['O'] = "01110";
  m['P'] = "01111";
  m['Q'] = "10000";
  m['R'] = "10001";
  m['S'] = "10010";
  m['T'] = "10011";
  m['U'] = "10100";
  m['V'] = "10101";
  m['W'] = "10110";
  m['X'] = "10111";
  m['Y'] = "11000";
  m['Z'] = "11001";
  m[' '] = "11010";
  m['.'] = "11011";
  m[','] = "11100";
  m['-'] = "11101";
  m['\''] = "11110";
  m['?'] = "11111";
  string ret = "";
  rep(i, code.size())
    ret += m[code[i]];

  return ret;
}

string decode(string code){
  string ret = "";

  map<string, char>m;
  m["101"] = ' ';
  m["000000"] = '\'';
  m["000011"] = ',';
  m["10010001"] = '-';
  m["010001"] = '.';
  m["000001"] = '?';
  m["100101"] = 'A';
  m["10011010"] = 'B';
  m["0101"] = 'C';
  m["0001"] = 'D';
  m["110"] = 'E';
  m["01001"] = 'F';
  m["10011011"] = 'G';
  m["010000"] = 'H';
  m["0111"] = 'I';
  m["10011000"] = 'J';
  m["0110"] = 'K';
  m["00100"] = 'L';
  m["10011001"] = 'M';
  m["10011110"] = 'N';
  m["00101"] = 'O';
  m["111"] = 'P';
  m["10011111"] = 'Q';
  m["1000"] = 'R';
  m["00110"] = 'S';
  m["00111"] = 'T';
  m["10011100"] = 'U';
  m["10011101"] = 'V';
  m["000010"] = 'W';
  m["10010010"] = 'X';
  m["10010011"] = 'Y';
  m["10010000"] = 'Z';

  rep(i, code.size()){
    string tmp = "";
    REP(j, i, code.size()){
      tmp += code[j];
      if(m.count(tmp) == 0) continue;
      //      cout << tmp << endl;

      ret += m[tmp];
      i = j;
      break;
    }
  }
  return ret;
}

int main(){
  while(getline(cin, str)){
    string res;
    res = encode(str);
    //    cout << res << endl;
    res = decode(res);
    cout << res << endl;
  }
  return 0;
}