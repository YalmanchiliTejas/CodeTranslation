#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<string,string> A, B;
map<string,string> rA, rB;

void init() {
  A["00000"] = "A";
  A["00001"] = "B";
  A["00010"] = "C";
  A["00011"] = "D";
  A["00100"] = "E";
  A["00101"] = "F";
  A["00110"] = "G";
  A["00111"] = "H";
  A["01000"] = "I";
  A["01001"] = "J";
  A["01010"] = "K";
  A["01011"] = "L";
  A["01100"] = "M";
  A["01101"] = "N";
  A["01110"] = "O";
  A["01111"] = "P";
  A["10000"] = "Q";
  A["10001"] = "R";
  A["10010"] = "S";
  A["10011"] = "T";
  A["10100"] = "U";
  A["10101"] = "V";
  A["10110"] = "W";
  A["10111"] = "X";
  A["11000"] = "Y";
  A["11001"] = "Z";
  A["11010"] = " ";
  A["11011"] = ".";
  A["11100"] = ",";
  A["11101"] = "-";
  A["11110"] = "'";
  A["11111"] = "?";
  for(map<string,string>::iterator it = A.begin();
      it != A.end(); ++it) {
    rA[it->second] = it->first;
  }

  B[" "] = "101";
  B["'"] = "000000";
  B[","] = "000011";
  B["-"] = "10010001";
  B["."] = "010001";
  B["?"] = "000001";
  B["A"] = "100101";
  B["B"] = "10011010";
  B["C"] = "0101";
  B["D"] = "0001";
  B["E"] = "110";
  B["F"] = "01001";
  B["G"] = "10011011";
  B["H"] = "010000";
  B["I"] = "0111";
  B["J"] = "10011000";
  B["K"] = "0110";
  B["L"] = "00100";
  B["M"] = "10011001";
  B["N"] = "10011110";
  B["O"] = "00101";
  B["P"] = "111";
  B["Q"] = "10011111";
  B["R"] = "1000";
  B["S"] = "00110";
  B["T"] = "00111";
  B["U"] = "10011100";
  B["V"] = "10011101";
  B["W"] = "000010";
  B["X"] = "10010010";
  B["Y"] = "10010011";
  B["Z"] = "10010000";
  for(map<string,string>::iterator it = B.begin();
      it != B.end(); ++it) {
    rB[it->second] = it->first;
  }
}

int main() {
  init();
  string s;
  while(getline(cin, s)) {
    string t, u;
    for(int i = 0; i < s.size(); ++i) {
      t += rA[string(1,s[i])];
    }
    int i = 0;
    for(; i < t.size(); ) {
      bool update = false;
      for(int j = 1; i+j <= t.size(); ++j) {
        string m = t.substr(i, j);
        if(rB.count(m)) {
          u += rB[m];
          i += j;
          update = true;
          break;
        }
      }
      if(!update) break;
    }
    cout << u << endl;
  }
  return 0;
}