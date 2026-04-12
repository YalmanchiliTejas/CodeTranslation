#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<complex>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef complex<double> P;

int main(){
  map<char,string> enc;
  map<string,char> dec;

  enc['A'] = "00000";
  enc['B'] = "00001";
  enc['C'] = "00010";
  enc['D'] = "00011";
  enc['E'] = "00100";
  enc['F'] = "00101";
  enc['G'] = "00110";
  enc['H'] = "00111";
  enc['I'] = "01000";
  enc['J'] = "01001";
  enc['K'] = "01010";
  enc['L'] = "01011";
  enc['M'] = "01100";
  enc['N'] = "01101";
  enc['O'] = "01110";
  enc['P'] = "01111";
  enc['Q'] = "10000";
  enc['R'] = "10001";
  enc['S'] = "10010";
  enc['T'] = "10011";
  enc['U'] = "10100";
  enc['V'] = "10101";
  enc['W'] = "10110";
  enc['X'] = "10111";
  enc['Y'] = "11000";
  enc['Z'] = "11001";
  enc[' '] = "11010";
  enc['.'] = "11011";
  enc[','] = "11100";
  enc['-'] = "11101";
  enc['\'']= "11110";
  enc['?'] = "11111";

  dec["101"] = ' ';
  dec["000000"] = '\'';
  dec["000011"] = ',';
  dec["10010001"] = '-';
  dec["010001"] = '.';
  dec["000001"] = '?';
  dec["100101"] = 'A';
  dec["10011010"] = 'B';
  dec["0101"] = 'C';
  dec["0001"] = 'D';
  dec["110"] = 'E';
  dec["01001"] = 'F';
  dec["10011011"] = 'G';
  dec["010000"] = 'H';
  dec["0111"] = 'I';
  dec["10011000"] = 'J';
  dec["0110"] = 'K';
  dec["00100"] = 'L';
  dec["10011001"] = 'M';
  dec["10011110"] = 'N';
  dec["00101"] = 'O';
  dec["111"] = 'P';
  dec["10011111"] = 'Q';
  dec["1000"] = 'R';
  dec["00110"] = 'S';
  dec["00111"] = 'T';
  dec["10011100"] = 'U';
  dec["10011101"] = 'V';
  dec["000010"] = 'W';
  dec["10010010"] = 'X';
  dec["10010011"] = 'Y';
  dec["10010000"] = 'Z';

  string input;
  while(getline(cin, input)){
    string buff = "";
    REP(i,input.size())
      buff += enc[input[i]];

    string ans,tmp;
    for(int i=0; i<buff.size(); i++){
      tmp += buff[i];
      if(dec.find(tmp) != dec.end()){
        ans += dec[tmp];
        tmp = "";
      }
    }

    cout << ans << endl;
  }
  return 0;
}