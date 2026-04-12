#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
string s;
char mo[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
string b;
map<string,char> m;
int main(void){
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
  while(getline(cin,s)){
    b = "";
    for(int i = 0; i < (int)s.size(); i++){
      for(int j = 0; mo[j] != '\0'; j++){
	if(s[i] == mo[j]){
	  for(int k = 4; k >= 0; k--){
	    b += ((j&(1<<k))?1:0)+'0';
	  }
	  break;
	}
      }
    }
    string t="";
    for(int i = 0; i < (int)b.size(); i++){
      t+=b[i];
      if(m.find(t) != m.end()){
	cout << m[t];
	t = "";
      }
    }
    cout << endl;
  }
}