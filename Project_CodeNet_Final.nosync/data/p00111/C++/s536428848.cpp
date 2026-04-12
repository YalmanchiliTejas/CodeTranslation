#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

string change1(string s){
  map<char, string> table;
  table['A'] = "00000";
  table['B'] = "00001";
  table['C'] = "00010";
  table['D'] = "00011";
  table['E'] = "00100";
  table['F'] = "00101";
  table['G'] = "00110";
  table['H'] = "00111";
  table['I'] = "01000";
  table['J'] = "01001";
  table['K'] = "01010";
  table['L'] = "01011";
  table['M'] = "01100";
  table['N'] = "01101";
  table['O'] = "01110";
  table['P'] = "01111";
  table['Q'] = "10000";
  table['R'] = "10001";
  table['S'] = "10010";
  table['T'] = "10011";
  table['U'] = "10100";
  table['V'] = "10101";
  table['W'] = "10110";
  table['X'] = "10111";  
  table['Y'] = "11000";
  table['Z'] = "11001";
  table[' '] = "11010";
  table['.'] = "11011";
  table[','] = "11100";
  table['-'] = "11101";
  table['\''] = "11110";
  table['?'] = "11111";
  
  string res = "";
  for(int i = 0 ; i < s.size() ; i++){
    res += table[s[i]];
  }
  return res;
}

string change2(string s){
  map<string, char> table;
  table["101"] = ' ';
  table["000000"] = '\'';
  table["000011"] = ',';
  table["10010001"] = '-';
  table["010001"] = '.';
  table["000001"] = '?';
  table["100101"] = 'A';
  table["10011010"] = 'B';
  table["0101"] = 'C';
  table["0001"] = 'D';
  table["110"] = 'E';
  table["01001"] = 'F';
  table["10011011"] = 'G';
  table["010000"] = 'H';
  table["0111"] = 'I';
  table["10011000"] = 'J';
  table["0110"] = 'K';
  table["00100"] = 'L';
  table["10011001"] = 'M';
  table["10011110"] = 'N';
  table["00101"] = 'O';
  table["111"] = 'P';
  table["10011111"] = 'Q';
  table["1000"] = 'R';
  table["00110"] = 'S';
  table["00111"] = 'T';
  table["10011100"] = 'U';
  table["10011101"] = 'V';
  table["000010"] = 'W';
  table["10010010"] = 'X';
  table["10010011"] = 'Y';
  table["10010000"] = 'Z';
  
  string res = "", tmp = "";
  
  for(int i = 0 ; i < s.size() ; i++){
    tmp += s[i];
    map<string, char>:: iterator it;
    it = table.find(tmp);
    if(it != table.end()){
      res += table[tmp];
      tmp = "";
    }
  }
  return res;
}
  
int main(){
  string str;
  while(getline(cin, str)){
    str = change1(str);
    str = change2(str);
    cout << str << endl;
  }
}