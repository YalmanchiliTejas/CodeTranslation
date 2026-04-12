#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <bitset>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<double> P;

int main() {
  string s;
  map<string, char> m;
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


  while(getline(cin, s)){
    stringstream ss, ans;
    REP(i, s.length()){
      if(s[i] == ' ') ss << "11010";
      else if(s[i] == '.') ss << "11011";
      else if(s[i] == ',') ss << "11100";
      else if(s[i] == '-') ss << "11101";
      else if(s[i] == '\'') ss << "11110";
      else if(s[i] == '?') ss << "11111";
      else{
        bitset<5> bs(s[i] - 'A');
        ss << bs.to_string();
      }
    }
    int i = 0;
    s = ss.str();
    while(i + 1 < s.length()){
      bool f = false;
      for(auto v : m){
        int l = v.first.length();
        if(v.first == s.substr(i, l)){
          ans << v.second;
          i += l;
          f = true;
          break;
        }
      }
      if(!f) break;
    }
    cout <<ans.str() <<endl;
  }
  return 0;
}