#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <bitset>
#include <map>
#include <utility>
using namespace std;

string itob(int n) {
  ostringstream oss;
  oss << bitset<5>(n);
  return oss.str();
}

int main() {
  map<char, string> ctob = {
    { ' ', itob(26) },
    { '.', itob(27) },
    { ',', itob(28) },
    { '-', itob(29) },
    { '\'', itob(30) },
    { '?', itob(31) }
  };
  for(char c = 'A'; c <= 'Z'; ++c) {
    ctob[c] = itob(c - 'A');
  }

  map<string, char> btoc = {
    { "101", ' ' },
    { "000000", '\'' },
    { "000011", ',' },
    { "10010001", '-' },
    { "010001", '.' },
    { "000001", '?' },
    { "100101", 'A' },
    { "10011010", 'B' },
    { "0101", 'C' },
    { "0001", 'D' },
    { "110", 'E' },
    { "01001", 'F' },
    { "10011011", 'G' },
    { "010000", 'H' },
    { "0111", 'I' },
    { "10011000", 'J' },
    { "0110", 'K' },
    { "00100", 'L' },
    { "10011001", 'M' },
    { "10011110", 'N' },
    { "00101", 'O' },
    { "111", 'P' },
    { "10011111", 'Q' },
    { "1000", 'R' },
    { "00110", 'S' },
    { "00111", 'T' },
    { "10011100", 'U' },
    { "10011101", 'V' },
    { "000010", 'W' },
    { "10010010", 'X' },
    { "10010011", 'Y' },
    { "10010000", 'Z' }
  };

  for(string S; getline(cin, S); ) {
    string bin;
    for(char c : S)
      bin += ctob[c];
    string ans;
    for(int i = 0; i < (int)bin.size(); ) {
      for(int j = 1; i + j <= (int)bin.size(); ++j) {
        string sub = bin.substr(i, j);
        if(btoc.count(sub)) {
          ans.push_back(btoc[sub]);
          i += j;
          goto next;
        }
      }
      break;
next:
      ;
    }
    cout << ans << endl;
  }
}