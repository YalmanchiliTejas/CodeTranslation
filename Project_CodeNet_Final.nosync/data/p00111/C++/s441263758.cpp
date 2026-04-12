#include<iostream>
using namespace std;

string code(char a){
  if(a =='A')return "00000";
  if(a =='B')return "00001";
  if(a =='C')return "00010";
  if(a =='D')return "00011";
  if(a =='E')return "00100";
  if(a =='F')return "00101";
  if(a =='G')return "00110";
  if(a =='H')return "00111";
  if(a =='I')return "01000";
  if(a =='J')return "01001";
  if(a =='K')return "01010";
  if(a =='L')return "01011";
  if(a =='M')return "01100";
  if(a =='N')return "01101";
  if(a =='O')return "01110";
  if(a =='P')return "01111";
  if(a =='Q')return "10000";
  if(a =='R')return "10001";
  if(a =='S')return "10010";
  if(a =='T')return "10011";
  if(a =='U')return "10100";
  if(a =='V')return "10101";
  if(a =='W')return "10110";
  if(a =='X')return "10111";
  if(a =='Y')return "11000";
  if(a =='Z')return "11001";
  if(a ==' ')return "11010";
  if(a =='.')return "11011";
  if(a ==',')return "11100";
  if(a =='-')return "11101";
  if(a =='\'')return "11110";
  if(a =='?')return "11111";
  return "none";
}

string decode(string a){
  string res;
  string table[32] = { "101", "000000", "000011", "10010001", "010001",
                       "000001", "100101", "10011010", "0101", "0001",
		       "110", "01001", "10011011", "010000", "0111",
		       "10011000", "0110", "00100", "10011001", "10011110",
		       "00101", "111", "10011111", "1000", "00110", "00111",
		       "10011100", "10011101", "000010", "10010010",
		       "10010011", "10010000"};
  int pos = 0,i;
  while(pos < (int)a.size()){
    for(i=0;i<32;i++){
      bool f = true;
      for(int j=0;j<(int)table[i].size();j++){
	if(a[pos+j] != table[i][j]){
	  f = false;
	  break;
	}
      }
      if(f){
	if(i>=6)res.push_back('A'+i-6);
	else{
	  if(i==0)res.push_back(' ');
	  if(i==1)res.push_back('\'');
	  if(i==2)res.push_back(',');
	  if(i==3)res.push_back('-');
	  if(i==4)res.push_back('.');
	  if(i==5)res.push_back('?');
	}
	pos += table[i].size();
	break;
      }
    }
    if(i==32)break;
  }
  return res;
}

int main(){
  string tmp;
  while(getline(cin,tmp)){
    string c;
    for(int i=0;i<(int)tmp.size();i++)c += code(tmp[i]);
    cout << decode(c) << endl;
  }
}