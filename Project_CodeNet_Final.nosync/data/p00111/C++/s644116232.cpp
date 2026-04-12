#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;
string henkan = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
map< string,char > sym;


void init() {
  sym["101"] = ' ';
  sym["000000"] = '\'';
  sym["000011"] = ',';
  sym["10010001"] = '-';
  sym["010001"] = '.';
  sym["000001"] = '?';
  sym["100101"] = 'A';
  sym["10011010"] = 'B';
  sym["0101"] = 'C';
  sym["0001"] = 'D';
  sym["110"] = 'E';
  sym["01001"] = 'F';
  sym["10011011"] = 'G';
  sym["010000"] = 'H';
  sym["0111"] = 'I';
  sym["10011000"] = 'J';
  sym["0110"] = 'K';
  sym["00100"] = 'L';
  sym["10011001"] = 'M';
  sym["10011110"] = 'N';
  sym["00101"] = 'O';
  sym["111"] = 'P';
  sym["10011111"] = 'Q';
  sym["1000"] = 'R';
  sym["00110"] = 'S';
  sym["00111"] = 'T';
  sym["10011100"] = 'U';
  sym["10011101"] = 'V';
  sym["000010"] = 'W';
  sym["10010010"] = 'X';
  sym["10010011"] = 'Y';
  sym["10010000"] = 'Z';
}
 
string _10to2(int a){
  string s2;
  for(int i = 0 ; i < 5 ; i++ ){
    s2 += (a%2 + '0');
    a /= 2; 
  }
  reverse(s2.begin(),s2.end());
  return s2;
}

int main(){
  init();
  string str;
  while(getline(cin,str)){
    string s = "";
    for(int i = 0 ; i < (int)str.size() ; i++ ){
      s += _10to2(henkan.find(str[i]));
    }
    string a = "";
    string tmp = "";
    for(int i = 0 ; i < (int)s.size() ; i++ ){
      tmp += s[i];
      if(sym.count(tmp)){
	a+=sym[tmp]; 
	tmp = "";
      }
    }
    cout << a << endl; 
  }
  return 0;
}