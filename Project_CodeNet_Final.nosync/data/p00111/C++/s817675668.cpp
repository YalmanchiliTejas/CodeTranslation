#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <string>
#include <cmath>
#include <map> 
#include <sstream>
#include <cstdio>
#include <complex>
#include <cstring>
using namespace std;
 
const int MAX= 10000100;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()
#define ll long long int
#define gcd(a,b) __gcd(a,b)
#define pb(a) push_back(a)
int GCD(int a, int b) {if(!b) return a; return gcd(b, a%b);}
int lcm(int a, int b) {return a*b / gcd(a, b);}

map<char,string> cs;
map<string,char> sc;

void add(){
  
  cs[' '] = "11010";
  cs['\''] = "11110";
  cs[','] = "11100";
  cs['-'] = "11101";
  cs['.'] = "11011";
  cs['?'] = "11111";
  cs['A'] = "00000";
  cs['B'] = "00001";
  cs['C'] = "00010";
  cs['D'] = "00011";
  cs['E'] = "00100";
  cs['F'] = "00101";
  cs['G'] = "00110";
  cs['H'] = "00111";
  cs['I'] = "01000";
  cs['J'] = "01001";
  cs['K'] = "01010";
  cs['L'] = "01011";
  cs['M'] = "01100";
  cs['N'] = "01101";
  cs['O'] = "01110";
  cs['P'] = "01111";
  cs['Q'] = "10000";
  cs['R'] = "10001";
  cs['S'] = "10010";
  cs['T'] = "10011";
  cs['U'] = "10100";
  cs['V'] = "10101";
  cs['W'] = "10110";
  cs['X'] = "10111";
  cs['Y'] = "11000";
  cs['Z'] = "11001";
  
  sc["100101"] = 'A';
  sc["10011010"] = 'B';
  sc["0101"] = 'C';
  sc["0001"] = 'D';
  sc["110"] = 'E';
  sc["01001"] = 'F';
  sc["10011011"] = 'G';
  sc["010000"] = 'H';
  sc["0111"] = 'I';
  sc["10011000"] = 'J';
  sc["0110"] = 'K';
  sc["00100"] = 'L';
  sc["10011001"] = 'M';
  sc["10011110"] = 'N';
  sc["00101"] = 'O';
  sc["111"] = 'P';
  sc["10011111"] = 'Q';
  sc["1000"] = 'R';
  sc["00110"] = 'S';
  sc["00111"] = 'T';
  sc["10011100"] = 'U';
  sc["10011101"] = 'V';
  sc["000010"] = 'W';
  sc["10010010"] = 'X';
  sc["10010011"] = 'Y';
  sc["10010000"] = 'Z';
  sc["101"] = ' ';
  sc["010001"] = '.';
  sc["000011"] = ',';
  sc["10010001"] = '-';
  sc["000000"] = '\'';
  sc["000001"] = '?';
}

int main(void){
  add();
  string s;
  while(getline(cin,s)){
    string bit;
    rep(i,s.size()){
      bit += cs[s[i]];
    }
    //cout<<bit<<endl;

    int st = 0;
    string ret = "";
    rep(i,bit.size()){
      //cout<<ret<<endl;
      if(sc[bit.substr(st,i-st+1)]){
	ret += sc[bit.substr(st,i-st+1)];
	st = i + 1;
      }
    }
    cout<<ret<<endl;
  }
}