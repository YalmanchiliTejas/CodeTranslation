#include <iostream>
#include <map>
#include <string>
using namespace std;

string st(char c) {
  if(c=='A') return "00000";
  if(c=='B') return "00001";
  if(c=='C') return "00010";
  if(c=='D') return "00011";
  if(c=='E') return "00100";
  if(c=='F') return "00101";
  if(c=='G') return "00110";
  if(c=='H') return "00111";
  if(c=='I') return "01000";
  if(c=='J') return "01001";
  if(c=='K') return "01010";
  if(c=='L') return "01011";
  if(c=='M') return "01100";
  if(c=='N') return "01101";
  if(c=='O') return "01110";
  if(c=='P') return "01111";
  if(c=='Q') return "10000";
  if(c=='R') return "10001";
  if(c=='S') return "10010";
  if(c=='T') return "10011";
  if(c=='U') return "10100";
  if(c=='V') return "10101";
  if(c=='W') return "10110";
  if(c=='X') return "10111";
  if(c=='Y') return "11000";
  if(c=='Z') return "11001";
  if(c==' ') return "11010";
  if(c=='.') return "11011";
  if(c==',') return "11100";
  if(c=='-') return "11101";
  if(c=='\'') return "11110";
  if(c=='?') return "11111";
}

int main() {
  map<string,char> m;
  m["101"]=' ';
  m["000000"]='\'';
  m["000011"]=',';
  m["10010001"]='-';
  m["010001"]='.';
  m["000001"]='?';
  m["100101"]='A';
  m["10011010"]='B';
  m["0101"]='C';
  m["0001"]='D';
  m["110"]='E';
  m["01001"]='F';
  m["10011011"]='G';
  m["010000"]='H';
  m["0111"]='I';
  m["10011000"]='J';
  m["0110"]='K';
  m["00100"]='L';
  m["10011001"]='M';
  m["10011110"]='N';
  m["00101"]='O';
  m["111"]='P';
  m["10011111"]='Q';
  m["1000"]='R';
  m["00110"]='S';
  m["00111"]='T';
  m["10011100"]='U';
  m["10011101"]='V';
  m["000010"]='W';
  m["10010010"]='X';
  m["10010011"]='Y';
  m["10010000"]='Z';
  string s;
  while(getline(cin,s)) {
    string t="";
    for(int i=0; i<s.size(); i++) t+=st(s[i]);
    string ans="";
    for(int i=0; i<t.size(); i++) {
      for(int j=1; j<9; j++) {
	string r=t.substr(i,j);
	if((m[r]>='A' && m[r]<='Z') || m[r]==' ' || m[r]=='.' || m[r]==',' || m[r]=='-' || m[r]=='\'' || m[r]=='?') {
	  ans+=m[r];
	  i+=j-1;
	  break;
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
