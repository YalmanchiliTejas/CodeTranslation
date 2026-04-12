#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
int main(void){
  map<string,string> data;
  data["101"] = " ";
  data["000000"] = "'";
  data["000011"] = ",";
  data["10010001"] = "-";
  data["010001"] = ".";
  data["000001"] = "?";
  data["100101"] = "A";
  data["10011010"] = "B";
  data["0101"] = "C";
  data["0001"] = "D";
  data["110"] = "E";
  data["01001"] = "F";
  data["10011011"] = "G";
  data["010000"] = "H";
  data["0111"] = "I";
  data["10011000"] = "J";
  data["0110"] = "K";
  data["00100"] = "L";
  data["10011001"] = "M";
  data["10011110"] = "N";
  data["00101"] = "O";
  data["111"] = "P";
  data["10011111"] = "Q";
  data["1000"] = "R";
  data["00110"] = "S";
  data["00111"] = "T";
  data["10011100"] = "U";
  data["10011101"] = "V";
  data["000010"] = "W";
  data["10010010"] = "X";
  data["10010011"] = "Y";
  data["10010000"] = "Z";
  map<string,string> data2;
  data2["A"] = "00000";
  data2["B"] = "00001";
  data2["C"] = "00010";
  data2["D"] = "00011";
  data2["E"] = "00100";
  data2["F"] = "00101";
  data2["G"] = "00110";
  data2["H"] = "00111";
  data2["I"] = "01000";
  data2["J"] = "01001";
  data2["K"] = "01010";
  data2["L"] = "01011";
  data2["M"] = "01100";
  data2["N"] = "01101";
  data2["O"] = "01110";
  data2["P"] = "01111";
  data2["Q"] = "10000";
  data2["R"] = "10001";
  data2["S"] = "10010";
  data2["T"] = "10011";
  data2["U"] = "10100";
  data2["V"] = "10101";
  data2["W"] = "10110";
  data2["X"] = "10111";
  data2["Y"] = "11000";
  data2["Z"] = "11001";
  data2[" "] = "11010";
  data2["."] = "11011";
  data2[","] = "11100";
  data2["-"] = "11101";
  data2["'"] = "11110";
  data2["?"] = "11111";
  string line;
  while(getline(cin,line)){
    string code;
    string ans;
    REP(i,line.size()){
      string cha = string(1,line[i]);
      code += data2[cha];
    }
    while(!code.empty()){
      bool f = true;
      REP(i,code.size()){
        string sub = code.substr(0,i+1);
        if(data.find(sub)!=data.end()){
          ans += data[sub];
          code.erase(0,i+1);
          f = false;
          break;
        }
      }
      if(f) break;
    }
    cout<<ans<<endl;
  }
  return 0;
}